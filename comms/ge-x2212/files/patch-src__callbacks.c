--- ./src/callbacks.c.orig	2010-09-16 00:10:17.000000000 +0000
+++ ./src/callbacks.c	2012-09-18 15:29:36.554081126 +0000
@@ -9,6 +9,11 @@
 #include "interface.h"
 #include "support.h"
 
+#ifdef USE_PPI_DEV
+#include <dev/ppbus/ppi.h>
+#include <dev/ppbus/ppbconf.h>
+#endif
+
 
 #ifdef __GLIBC__
 #include <sys/io.h>
@@ -20,6 +25,7 @@
 #define DIRBIT 0x20
 
 extern  GtkWidget *app1;
+extern gboolean uhf;
 
 // new port defines to get 0x378 working on lp0
 #define LPTBASE 0x378
@@ -76,6 +82,36 @@
                     "ch09cct", "ch10cct", "ch11cct", "ch12cct",
                     "ch13cct", "ch14cct", "ch15cct", "ch16cct" };
                     
+#ifdef USE_PPI_DEV
+static void ppi_outb(u_int8_t outb_val, int addr) {
+	int			outb_action=-1;
+
+	if(addr==LPTBASE || addr==LPTDAT)
+		outb_action=PPISDATA;
+	else if(addr==LPTSTAT)
+		outb_action=PPISSTATUS;
+	else if(addr==LPTCTRL)
+		outb_action=PPISCTRL;
+	ioctl(fd0, outb_action, &outb_val);
+}
+
+static u_int8_t ppi_inb(int addr)
+{
+	u_int8_t ret=0;
+
+	if(addr==LPTBASE || addr==LPTDAT)
+		ioctl(fd0, PPIGDATA, &ret);
+	else if(addr==LPTSTAT)
+		ioctl(fd0, PPIGSTATUS, &ret);
+	else if(addr==LPTCTRL)
+		ioctl(fd0, PPIGCTRL, &ret);
+	return ret;
+}
+
+#define outb(v,a)	ppi_outb((v),(a))
+#define inb(a)		ppi_inb(a)
+#endif
+
 /* convert 2 ascii chars in hex to a decimal number */
 static int hex2( unsigned char a, unsigned char b)
 {
@@ -111,7 +147,9 @@
     /* release parallel port */
     if (fd0 > 0)
         close(fd0);
+#ifndef USE_PPI_DEV
     ioperm(LPTDAT, 3, 0);
+#endif
 }
 //=====================================================================
 // 
@@ -209,6 +247,7 @@
         case 0x03: space = 6250.0;      break;
         default: fprintf(stderr,"Invalid channel spacing code %d\n",r);
         }
+        if(uhf) space *= 3;
 
 //      g_print("ref = %fhz, spacing = %fhz \n",ref,space);        
         
@@ -736,6 +775,35 @@
     return 0;
 }
 
+gboolean freq_good(double freq)
+{
+	if(uhf)
+		return ( freq >= 134.33*3 && freq <= 185.66*3 );
+	return ( freq >= 136.0 && freq <= 174.0 );
+}
+
+int calc_divisor(double freq, double space, gboolean is_rx)
+{
+	int divisor = (((freq + (is_rx?45.0:0))*1e6) + (space/2.0)) / space;
+	/* Out of range... */
+	if(divisor > 0xffff || divisor < 0)
+		divisor=0;
+	return divisor;
+}
+
+double calc_realfreq(int divisor, double space, gboolean is_rx)
+{
+	return ((divisor * space ) - (is_rx?45e6:0))/1e6;  /* in mhz */
+}
+
+void fill_ch(unsigned char *chbuff, int divisor)
+{
+	chbuff[1] = ( divisor & 0x8000) >> 12;
+	chbuff[2] = (divisor & 0x780) >> 7;
+	chbuff[3] = (divisor & 0x7800) >> 11;
+	chbuff[4] = divisor & 0xf;
+	chbuff[5] = ((divisor & 0x30) >> 4) + ((divisor & 0x40) >> 3);
+}
 
 //=====================================================================
 // 
@@ -743,15 +811,37 @@
 //=====================================================================
 void encoderom( void )
 {
-    int i;
+    int i,j;
     int chan; 
-    double freq, realfreq;
+    double realfreq;
+    double rx_freq;
+    double tx_freq;
     int divisor;
     unsigned char *chbuff;
-    
+    double spaces[3];
+    double errors[3];
+    int spacecode[3];
+    int sc_idx;
+
+    if(uhf) {
+		spaces[0]=12500.0;
+		spaces[1]=15000.0;
+		spaces[2]=18750.0;
+		spacecode[0]=1;
+		spacecode[1]=2;
+		spacecode[2]=3;
+	}
+    else {
+		spaces[0]=5000.0;
+		spaces[1]=12500.0/3.0;
+		spaces[2]=6250.0;
+		spacecode[0]=2;
+		spacecode[1]=1;
+		spacecode[2]=3;
+    }
     GtkWidget *wid;
     G_CONST_RETURN gchar *txt;
-    
+
     /* start with a clean image */
     memset(x2212,0,sizeof(x2212));
 
@@ -778,55 +868,61 @@
         /* single digit conversion */
         x2212[0x40] = hex2bin(txt[0]) - 1;
 
-    /* number of channels in radio... to do this we need to look    */
-    /* at all the rx channels and count any in the range of 136-174 */
-    chan = 0;
-    for ( i = 0; i<16; i++ )
-    {
-        wid = lookup_widget(app1,rxfreq[i]);
-        txt = gtk_entry_get_text((GtkEntry *)wid);
-        freq = atof(txt);
-        if ( freq >= 136.0 && freq <= 174.0 ) chan++;
-    }
-    if ( chan < 1 )
-        fprintf(stderr,"Warning, no valid channels found\n");
-    x2212[0x80] = chan - 1;
-    
+	chan=0;
     /* now lets fill in all the channels */
     for ( i = 0; i<16; i++ )
     {
         /* rx freq lookup off the screen */
         wid = lookup_widget(app1,rxfreq[i]);
         txt = gtk_entry_get_text((GtkEntry *)wid);
-        freq = atof(txt);
+        rx_freq = atof(txt);
+
+       	if ( !freq_good(rx_freq) ) {
+			if(rx_freq > 0)
+				g_printf("Warning, ignoring and removing invalid channel %d\n",i+1);
+       		continue;
+       	}
+       	chan++;
+		if(chan != i+1)
+			g_printf("Warning, channel %d will be renumbered to %d\n",i+1,chan);
+
+        /* tx freq lookup off the screen */
+        wid = lookup_widget(app1,txfreq[i]);
+        txt = gtk_entry_get_text((GtkEntry *)wid);
+        tx_freq = atof(txt);
+
+		for(j=0; j<3; j++) {
+            divisor = calc_divisor(rx_freq, spaces[j], TRUE);
+            realfreq = calc_realfreq(divisor, spaces[j], TRUE);  /* in mhz */
+            errors[j] = fabs(rx_freq-realfreq);
+            divisor = calc_divisor(tx_freq, spaces[j], FALSE);
+            realfreq = calc_realfreq(divisor, spaces[j], FALSE);  /* in mhz */
+            errors[j] += fabs(tx_freq-realfreq)*2;
+		}
+		sc_idx=0;
+		for(j=1; j<3; j++) {
+			if(errors[j] < errors[sc_idx])
+				sc_idx=j;
+		}
+//		if(sc_idx)
+//			g_printf("Using non-standard spacing of %fHz for channel %d\n",spaces[sc_idx],i+1);
 
-        /* 3 gross assumptions!!!, timebomb below */
         ref = 13.2e6;
-        space = 5000.0;
-#define REFCODE 2        
 
         /* point to the 8 bytes of rx channel data for specified channel */
-        chbuff = &x2212[0] + (((i+1) % 16) * 16);
+        chbuff = &x2212[0] + ((chan % 16) * 16);
         /* there are 20 packed bits of freq info... lets build the numbers */
         
         /* fill in info for valid rx channels */
-        if ( freq >= 136.0 && freq <= 174.0 )
+        if ( freq_good(rx_freq) )
         {
-            /* we have a choice of 3 ch spacings when building info */
-            /* for a particular rx and tx channel pair              */
-            /* as a start, we assume 5khz will do.. should probably */
-            /* try all 3 and use the one with the least error       */
-            divisor = (((freq + 45.0)*1e6) + (space/2.0)) / space;
-            realfreq = ((divisor * space ) - 45e6)/1e6;  /* in mhz */
-            if ( fabs(freq-realfreq) > 0.001 )
+            divisor = calc_divisor(rx_freq, spaces[sc_idx], TRUE);
+            realfreq = calc_realfreq(divisor, spaces[sc_idx], TRUE);  /* in mhz */
+            if ( fabs(rx_freq-realfreq) > 0.001 )
                 fprintf(stderr,"Warning ch %d freq error: %f <> %fmhz\n",
-                        i+1,realfreq,freq); 
-            chbuff[1] = REFCODE + (( divisor & 0x8000) >> 12);
-            chbuff[2] = (divisor & 0x780) >> 7;
-            chbuff[3] = (divisor & 0x7800) >> 11;
-            chbuff[4] = divisor & 0xf;
-            chbuff[5] = ((divisor & 0x30) >> 4) + ((divisor & 0x40) >> 3);
-
+                        i+1,realfreq,rx_freq); 
+			fill_ch(chbuff, divisor);
+            chbuff[1] |= spacecode[sc_idx];
         }
         /* fill in the rx cg code (1st 2 digits of entrybox) */
         wid = lookup_widget(app1,rxcg[i]);
@@ -835,28 +931,19 @@
         chbuff[7] = hex2bin(txt[1]);
 
         /* now fill in the tx info */
-        /* tx freq lookup off the screen */
-        wid = lookup_widget(app1,txfreq[i]);
-        txt = gtk_entry_get_text((GtkEntry *)wid);
-        freq = atof(txt);
-
         /* point to the 8 bytes of tx channel data for specified channel */
-        chbuff = &x2212[0] + (((i+1) % 16) * 16) + 8;
+        chbuff = &x2212[0] + ((chan % 16) * 16) + 8;
         /* there are 20 packed bits of freq info... lets build the numbers */
         
         /* fill in info for valid tx channels */
-        if ( freq >= 136.0 && freq <= 174.0 )
+        if ( freq_good(tx_freq) )
         {
-            divisor = ((freq*1e6) + (space/2.0)) / space;
-            realfreq = divisor * space /1e6;  /* in mhz */
-            if ( fabs(freq-realfreq) > 0.001 )
+            divisor = calc_divisor(tx_freq, spaces[sc_idx], FALSE);
+            realfreq = calc_realfreq(divisor, spaces[sc_idx], FALSE);  /* in mhz */
+            if ( fabs(tx_freq-realfreq) > 0.001 )
                 fprintf(stderr,"Warning ch %d freq error: %f <> %fmhz\n",
-                        i+1,realfreq,freq); 
-            chbuff[1] = ( divisor & 0x8000) >> 12;
-            chbuff[2] = (divisor & 0x780) >> 7;
-            chbuff[3] = (divisor & 0x7800) >> 11;
-            chbuff[4] = divisor & 0xf;
-            chbuff[5] = ((divisor & 0x30) >> 4) + ((divisor & 0x40) >> 3);
+                        i+1,realfreq,tx_freq);
+			fill_ch(chbuff, divisor);
         }
         /* fill in the tx cg code (1st 2 digits of entrybox) */
         wid = lookup_widget(app1,txcg[i]);
@@ -869,6 +956,11 @@
         if (gtk_toggle_button_get_active((GtkToggleButton *)wid))
             chbuff[1] = chbuff[1] + 0x04;
     }
+    /* number of channels in radio... to do this we need to look    */
+    /* at all the rx channels and count any in the range of 136-174 */
+    if ( chan < 1 )
+        fprintf(stderr,"Warning, no valid channels found\n");
+    x2212[0x80] = chan - 1;
 }
 
 
@@ -1148,19 +1240,30 @@
     }
 
     /* to read and write to the parallel port, we need it open as root */
+#ifdef USE_PPI_DEV
+    fd0 = open("/dev/ppi0", O_RDWR | O_NONBLOCK);
+#else
     fd0 = open("/dev/lp0", O_RDWR | O_NONBLOCK);
+#endif
     if (fd0 >= 0) 
     {
+#ifndef USE_PPI_DEV
         int stat = ioperm(LPTDAT, 3, 1);
     	if ( stat == -1 )
 	        perror("ioperm failed ");
+#endif
     }
     else
     {
+#ifdef USE_PPI_DEV
+        fprintf(stderr,"\n\n*** open on /dev/ppi0 failed...Do you have permission?\n");
+    	perror("/dev/lp0");
+#else
         fprintf(stderr,"\n\n*** open on /dev/lp0 failed...Do you have permission?\n");
         fprintf(stderr,"*** you may need to 'sudo modprobe parport_pc'\n");
         fprintf(stderr,"*** 'sudo ge-x2212-2'\n");
     	perror("/dev/lp0");
+#endif
         done();
     }
 //  g_print("Using port: 0x%x \n", LPTDAT);
