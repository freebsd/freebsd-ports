diff -urN DAPA.C.orig DAPA.C
--- DAPA.C.orig	Tue Aug 29 17:08:28 2000
+++ DAPA.C	Fri Feb 16 20:57:23 2001
@@ -20,6 +20,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#if !defined (__FreeBSD__)
 #include <linux/serial_reg.h>
 
 /* sys/io.h is the correct file.  If your system doesn't have that
@@ -35,8 +36,20 @@
 #endif
 */
 #include "io_uisp.h"
+#endif
 
 #include <unistd.h>
+
+#if defined(__FreeBSD__)
+#define __KERNEL__
+#define LP_STATS
+#include "linux_lp.h"
+#undef __KERNEL__
+#undef LP_STATS
+#include "linux_serial_reg.h"
+#endif
+
+#if !defined (__FreeBSD__)
 #ifdef DIRTYHACK
 #define __KERNEL__
 #endif
@@ -44,6 +57,14 @@
 #ifdef DIRTYHACK
 #undef __KERNEL__
 #endif
+#else
+#include <sys/fcntl.h>
+#include <machine/cpufunc.h>
+#include <machine/sysarch.h>
+#define ioperm i386_set_ioperm
+#define _outb(a,b) outb(b,a)
+#endif
+
 #include <signal.h>
 #include <sys/time.h>
 #include "Global.h"
@@ -133,51 +154,51 @@
 void TDAPA::Reset(){
   switch(pa_type){
   case PAT_DAPA:
-    outb(DAPA_SCK, BASE+2); usleep(1000);      /* sck = 0, reset = 0 */
-    outb(DAPA_SCK | DAPA_RESET, BASE+2);       /* sck = 0, reset = 1 */
+    _outb(DAPA_SCK, BASE+2); usleep(1000);      /* sck = 0, reset = 0 */
+    _outb(DAPA_SCK | DAPA_RESET, BASE+2);       /* sck = 0, reset = 1 */
     usleep(1000);
-    outb(DAPA_SCK, BASE+2); usleep(1000);      /* sck = 0, reset = 0 */
+    _outb(DAPA_SCK, BASE+2); usleep(1000);      /* sck = 0, reset = 0 */
     break;
 
   case PAT_DASA:
-    outb(UART_LCR_WLEN8 | UART_LCR_SBC, UART_LCR+BASE); /* select IER and FCR */
-    outb(UART_MCR_DTR | UART_MCR_RTS, UART_MCR+BASE); /* enable port, no int. */
-    outb(0, UART_IER+BASE); /* disable int */
-    outb(UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT, UART_FCR+BASE); /* disable fifo */
+    _outb(UART_LCR_WLEN8 | UART_LCR_SBC, UART_LCR+BASE); /* select IER and FCR */
+    _outb(UART_MCR_DTR | UART_MCR_RTS, UART_MCR+BASE); /* enable port, no int. */
+    _outb(0, UART_IER+BASE); /* disable int */
+    _outb(UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT, UART_FCR+BASE); /* disable fifo */
     inb(UART_LSR+BASE); /* read int flags to clear them for good */
     inb(UART_RX+BASE); /* read int flags to clear them for good */
     inb(UART_IIR+BASE); /* read int flags to clear them for good */
     inb(UART_MSR+BASE); /* read int flags to clear them for good */
     usleep(100000); /* clk = sck = reset = 1 */
-    outb(0, UART_LCR+BASE); usleep(1000); /* clk = 0, sck = 1, reset = 1 */
-    outb(DASA_RESET, UART_MCR+BASE); usleep(1000); /* clk = 0, sck = 0, reset = 1 */
-    outb(0, UART_MCR+BASE); usleep(1000); /* clk = 0, sck = 0, reset = 0 */
+    _outb(0, UART_LCR+BASE); usleep(1000); /* clk = 0, sck = 1, reset = 1 */
+    _outb(DASA_RESET, UART_MCR+BASE); usleep(1000); /* clk = 0, sck = 0, reset = 1 */
+    _outb(0, UART_MCR+BASE); usleep(1000); /* clk = 0, sck = 0, reset = 0 */
     break;
 
   case PAT_STK200:
-    outb(STK2_ENA1 | STK2_ENA2, BASE);    	/* leave MCU */
+    _outb(STK2_ENA1 | STK2_ENA2, BASE);    	/* leave MCU */
     usleep(30000);
-    outb(STK2_ENA2, BASE); usleep(1000);	/* sck = Z, reset = 0 */
-    outb(0, BASE); usleep(1000);  		/* sck = 0, reset = 0 */
-    outb(STK2_RESET, BASE); usleep(1000); 	/* sck = 0, reset = 1 */
-    outb(0, BASE); usleep(1000);         	/* sck = 0, reset = 0 */       
+    _outb(STK2_ENA2, BASE); usleep(1000);	/* sck = Z, reset = 0 */
+    _outb(0, BASE); usleep(1000);  		/* sck = 0, reset = 0 */
+    _outb(STK2_RESET, BASE); usleep(1000); 	/* sck = 0, reset = 1 */
+    _outb(0, BASE); usleep(1000);         	/* sck = 0, reset = 0 */       
     break;
     
   case PAT_ABB:
-    outb(0,BASE+2); usleep(30000);		/* leave MCU */
-    outb(0,BASE); 				/* reset=sck=0 */
-    outb(ABB_EN,BASE+2); usleep(30000);		/* enable 244 driver */
-    outb(ABB_RESET,BASE); usleep(30000);	/* reset=1 */
-    outb(0,BASE); usleep(30000);		/* reset=0*/    
+    _outb(0,BASE+2); usleep(30000);		/* leave MCU */
+    _outb(0,BASE); 				/* reset=sck=0 */
+    _outb(ABB_EN,BASE+2); usleep(30000);		/* enable 244 driver */
+    _outb(ABB_RESET,BASE); usleep(30000);	/* reset=1 */
+    _outb(0,BASE); usleep(30000);		/* reset=0*/    
 //    fprintf(stderr, "quiting ... test\n"); exit(1);
     break;
 
   case PAT_AVRISP:
-    outb(AVRISP_ENA, BASE);    			/* leave MCU */
+    _outb(AVRISP_ENA, BASE);    			/* leave MCU */
     usleep(30000);
-    outb(0, BASE); usleep(1000);  		/* sck = 0, reset = 0 */
-    outb(AVRISP_RESET, BASE); usleep(1000); 	/* sck = 0, reset = 1 */
-    outb(0, BASE); usleep(1000);         	/* sck = 0, reset = 0 */       
+    _outb(0, BASE); usleep(1000);  		/* sck = 0, reset = 0 */
+    _outb(AVRISP_RESET, BASE); usleep(1000); 	/* sck = 0, reset = 1 */
+    _outb(0, BASE); usleep(1000);         	/* sck = 0, reset = 0 */       
     break;
 
   }
@@ -188,7 +209,7 @@
 void TDAPA::JustReset(){
   switch(pa_type){
   case PAT_DAPA:
-    outb(DAPA_SCK | DAPA_RESET, BASE+2);       /* sck = 0, reset = 1 */
+    _outb(DAPA_SCK | DAPA_RESET, BASE+2);       /* sck = 0, reset = 1 */
     break;
     
   case PAT_DASA:
@@ -196,16 +217,16 @@
     break;    
 
   case PAT_STK200:
-    outb(STK2_ENA2 | STK2_RESET, BASE);                /* sck = Z, reset = 1 */
+    _outb(STK2_ENA2 | STK2_RESET, BASE);                /* sck = Z, reset = 1 */
     break;
     
   case PAT_ABB:
-    outb(ABB_EN,BASE+2);                       /* enable 244 driver */
-    outb(ABB_RESET,BASE);                      /* reset=1 */
+    _outb(ABB_EN,BASE+2);                       /* enable 244 driver */
+    _outb(ABB_RESET,BASE);                      /* reset=1 */
     break;
 
   case PAT_AVRISP:
-    outb(AVRISP_ENA | AVRISP_RESET, BASE);     /* Leave MCU, reset = 1 */
+    _outb(AVRISP_ENA | AVRISP_RESET, BASE);     /* Leave MCU, reset = 1 */
     break;
   }
   usleep(20000);
@@ -214,28 +235,28 @@
 void TDAPA::SCKtoRetryEnable(){
   switch(pa_type){
   case PAT_DAPA:
-    outb(0, BASE+2); BigDelay();
-    outb(DAPA_SCK, BASE+2); BigDelay();
+    _outb(0, BASE+2); BigDelay();
+    _outb(DAPA_SCK, BASE+2); BigDelay();
     break;
 
   case PAT_DASA:
-    outb (DASA_SCK, UART_MCR+BASE); BigDelay ();  /* sck = 1 */
-    outb (0, UART_MCR+BASE); BigDelay ();  /* sck = 0 */
+    _outb (DASA_SCK, UART_MCR+BASE); BigDelay ();  /* sck = 1 */
+    _outb (0, UART_MCR+BASE); BigDelay ();  /* sck = 0 */
     break;
 
   case PAT_STK200:
-    outb(STK2_SCK, BASE); BigDelay();  	/* sck = 1 */
-    outb(0, BASE); BigDelay();  	/* sck = 0 */
+    _outb(STK2_SCK, BASE); BigDelay();  	/* sck = 1 */
+    _outb(0, BASE); BigDelay();  	/* sck = 0 */
     break;
 
   case PAT_ABB:
-    outb(ABB_SCK, BASE); BigDelay();
-    outb(0, BASE); BigDelay();
+    _outb(ABB_SCK, BASE); BigDelay();
+    _outb(0, BASE); BigDelay();
     break;    
 
   case PAT_AVRISP:
-    outb(AVRISP_SCK, BASE); BigDelay(); /* sck = 1 */
-    outb(0, BASE); BigDelay();		/* sck = 0 */
+    _outb(AVRISP_SCK, BASE); BigDelay(); /* sck = 1 */
+    _outb(0, BASE); BigDelay();		/* sck = 0 */
     break;    
   }
 }
@@ -246,56 +267,56 @@
   for (i=0, mask = 0x80; i<8; i++, mask >>= 1){
      switch(pa_type){
      case PAT_DAPA:
-       outb(b & mask ? DAPA_DOUT : 0, BASE); BigDelay();
-       outb(0, BASE+2); BigDelay ();
+       _outb(b & mask ? DAPA_DOUT : 0, BASE); BigDelay();
+       _outb(0, BASE+2); BigDelay ();
        if (!(inb (BASE+1) & DAPA_DIN)){received |= mask;}
-       outb(DAPA_SCK, BASE+2); BigDelay();
+       _outb(DAPA_SCK, BASE+2); BigDelay();
        break;
      
      case PAT_DASA:
-       outb((b & mask) ? DASA_MOSI : 0, UART_LCR+BASE); /* send data bit, sck = 0 */
-       outb(DASA_SCK, UART_MCR+BASE); /* send data bit, sck = 1 */
+       _outb((b & mask) ? DASA_MOSI : 0, UART_LCR+BASE); /* send data bit, sck = 0 */
+       _outb(DASA_SCK, UART_MCR+BASE); /* send data bit, sck = 1 */
        if(longsck > -2)
         BigDelay();
        if(i == 0 && longsck > 5) usleep(longsck); /* allow recharging of the capacitor */
        if (inb(UART_MSR+BASE) & DASA_MISO){received |= mask;} /* read data bit */  
-       outb(0, UART_MCR+BASE); /* send data bit, sck = 0 */
-       outb(DASA_MOSI, UART_LCR+BASE); /* power it up */
+       _outb(0, UART_MCR+BASE); /* send data bit, sck = 0 */
+       _outb(DASA_MOSI, UART_LCR+BASE); /* power it up */
        if(longsck > -1)
         BigDelay();
        break;
 
      case PAT_STK200:
-       outb((b & mask) ? STK2_DOUT : 0, BASE);  /* send data bit, sck = 0 */
+       _outb((b & mask) ? STK2_DOUT : 0, BASE);  /* send data bit, sck = 0 */
        BigDelay();
        if (inb(BASE + 1) & STK2_DIN){received |= mask;} /* read data bit */
        						/* send data bit, sck = 1 */
-       outb(STK2_SCK | ((b & mask) ? STK2_DOUT : 0), BASE);  
+       _outb(STK2_SCK | ((b & mask) ? STK2_DOUT : 0), BASE);  
        BigDelay();
-       outb((b & mask) ? STK2_DOUT : 0, BASE);	/* send data bit, sck = 0 */
+       _outb((b & mask) ? STK2_DOUT : 0, BASE);	/* send data bit, sck = 0 */
        BigDelay();
        break;
        
      case PAT_ABB:
-       outb((b & mask) ? ABB_DOUT : 0, BASE);  /* send data bit, sck = 0 */
+       _outb((b & mask) ? ABB_DOUT : 0, BASE);  /* send data bit, sck = 0 */
        BigDelay();
        if (!(inb(BASE + 1) & ABB_DIN)){received |= mask;} /* read data bit */
        						/* send data bit, sck = 1 */
-       outb(ABB_SCK | ((b & mask) ? ABB_DOUT : 0), BASE);  
+       _outb(ABB_SCK | ((b & mask) ? ABB_DOUT : 0), BASE);  
        BigDelay();
-       outb((b & mask) ? ABB_DOUT : 0, BASE);	/* send data bit, sck = 0 */
+       _outb((b & mask) ? ABB_DOUT : 0, BASE);	/* send data bit, sck = 0 */
        BigDelay();
        break;
 
      case PAT_AVRISP:
-       outb((b & mask) ? AVRISP_DOUT : 0, BASE);  /* send data bit, sck = 0 */
+       _outb((b & mask) ? AVRISP_DOUT : 0, BASE);  /* send data bit, sck = 0 */
        BigDelay();
        if (inb(BASE + 1) & AVRISP_DIN){received |= mask;} /* read data bit */
        						/* send data bit, sck = 1 */
        
-       outb(AVRISP_SCK | ((b & mask) ? AVRISP_DOUT : 0), BASE);  
+       _outb(AVRISP_SCK | ((b & mask) ? AVRISP_DOUT : 0), BASE);  
        BigDelay();
-       outb((b & mask) ? AVRISP_DOUT : 0, BASE);	/* send data bit, sck = 0 */
+       _outb((b & mask) ? AVRISP_DOUT : 0, BASE);	/* send data bit, sck = 0 */
        BigDelay();
        break;
      }
@@ -397,9 +418,9 @@
   if (pa_type == PAT_AVRISP) { /* Check if dongle is present */
     unsigned char avrisp_present=1;
 
-    outb(AVRISP_DNG_OUT | AVRISP_ENA, BASE);
+    _outb(AVRISP_DNG_OUT | AVRISP_ENA, BASE);
     if (!(inb(BASE+1)&AVRISP_DNG_IN)) avrisp_present=0; 
-    outb(AVRISP_ENA, BASE);
+    _outb(AVRISP_ENA, BASE);
     if (inb(BASE+1)&AVRISP_DNG_IN) avrisp_present=0;
     if (!(inb(BASE+1)&AVRISP_DNG_IN1)) avrisp_present=0;
     if (!avrisp_present) {
@@ -410,12 +431,12 @@
 
 TDAPA::~TDAPA(){
   switch(pa_type){  
-  case PAT_DAPA:   outb(DAPA_SCK | DAPA_RESET, BASE+2); break;
-  case PAT_DASA:   outb(DASA_RESET | DASA_SCK, UART_MCR+BASE);
-                   outb(DASA_MOSI, UART_LCR+BASE); break;
-  case PAT_STK200: outb(STK2_ENA1 | STK2_ENA2 | STK2_RESET, BASE); break;
-  case PAT_ABB:    outb(0, BASE+2); outb(ABB_RESET, BASE); break;
-  case PAT_AVRISP: outb(AVRISP_ENA | AVRISP_RESET, BASE);   break;
+  case PAT_DAPA:   _outb(DAPA_SCK | DAPA_RESET, BASE+2); break;
+  case PAT_DASA:   _outb(DASA_RESET | DASA_SCK, UART_MCR+BASE);
+                   _outb(DASA_MOSI, UART_LCR+BASE); break;
+  case PAT_STK200: _outb(STK2_ENA1 | STK2_ENA2 | STK2_RESET, BASE); break;
+  case PAT_ABB:    _outb(0, BASE+2); _outb(ABB_RESET, BASE); break;
+  case PAT_AVRISP: _outb(AVRISP_ENA | AVRISP_RESET, BASE);   break;
   }
 }
