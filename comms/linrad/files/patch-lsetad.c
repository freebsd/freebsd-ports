--- lsetad.c.orig	Sat May 27 07:48:22 2006
+++ lsetad.c	Mon Jun 19 21:43:19 2006
@@ -36,14 +36,13 @@
 
 
 #define SNDLOG fprintf(sndlog,
-#define ABOVE_MAX_SPEED 768000
 #if SND_DEV == 1
 #define DEVNAME_SIZE 12
-char devname[DEVNAME_SIZE]="/dev/dsp   ";
+char dev_name[DEVNAME_SIZE]="/dev/dsp   ";
 #define DEVNAMPOS 8
 #else 
 #define DEVNAME_SIZE 18
-char devname[DEVNAME_SIZE]="/dev/sound/dsp   ";
+char dev_name[DEVNAME_SIZE]="/dev/sound/dsp   ";
 #define DEVNAMPOS 14
 #endif
 int devmodes[3]={O_RDONLY,O_WRONLY,O_RDWR};
@@ -58,6 +57,7 @@
                               22050,24000,48000,96000};
 
 FILE *sndlog;
+int tspeed;
 
 // Mod1:    Get info from OSS or ALSA sound-driver about the defined audio
 //          devices.
@@ -481,31 +481,12 @@
 
 void make_devname(int n)
 {
-int k,num,m;
-num=n;
-k=DEVNAMPOS;
-if(num>MAX_DEVNAMES)
+if(n>MAX_DEVNAMES)
   {
   lirerr(9236);
   return;
   }
-m=num/10;
-if(m > 0)
-  {
-  devname[k]=m+'0';
-  k++;
-  }
-devname[k]=num-m*10+'0';
-if(devname[k]<'0')devname[k]=0;
-k++;
-devname[k]=0;  
-// put /dev/dsp at the end of the list
-if ((n+2)==MAX_DEVNAMES){
-   k=DEVNAMPOS;
-   devname[k]=0;
-   k++;
-   devname[k]=0; 
-   }
+  sprintf(dev_name, "/dev/dspW%d", n);
 }
 // -------------------------------------------------------------
 // The original code was:
@@ -557,7 +538,7 @@
 if(i&AFMT_S16_LE)ui.max_output_bytes=2;
 ui.max_output_speed=ABOVE_MAX_SPEED;
 ui.min_output_speed=1;
-if(ioctl(audio_out, SNDCTL_DSP_SPEED, &ui.max_output_speed) == -1)
+if(ioctl(audio_out, SNDCTL_DSP_SPEED, &ui.min_output_speed) == -1)
   {
   lirerr(1072);
   return;
@@ -666,7 +647,7 @@
   return;
   }
 make_devname(ui.ad_device_no&255);
-audio_in=open( devname ,ui.ad_device_mode , 0);
+audio_in=open( dev_name ,ui.ad_device_mode , 0);
 if(audio_in == -1)
   {
   lirerr(1007);
@@ -676,7 +657,7 @@
   {
   i=ui.ad_device_no/255-1;
   make_devname(i);
-  audio_in2=open( devname ,ui.ad_device_mode , 0);
+  audio_in2=open( dev_name ,ui.ad_device_mode , 0);
   if(audio_in2 == -1)
     {
     lirerr(1174);
@@ -869,7 +850,7 @@
       return;
       }
     make_devname(ui.ad_device_no&255);
-    audio_out=open( devname ,O_WRONLY , 0);
+    audio_out=open( dev_name ,O_WRONLY , 0);
     if(audio_out == -1)
       {
       lirerr(1086);
@@ -909,7 +890,7 @@
 else
   {
   make_devname(ui.da_device_no);
-  audio_out=open( devname ,O_WRONLY , 0);
+  audio_out=open( dev_name ,O_WRONLY , 0);
   if(audio_out == -1)
     {
     if(disksave_flag==2)
@@ -1048,9 +1029,9 @@
 for(device_no=0; device_no<MAX_DEVNAMES; device_no++)
   {
   make_devname(device_no);
-  SNDLOG"Checking %s for output\n",devname);
+  SNDLOG"Checking %s for output\n",dev_name);
   sndlog_sync();
-  audio_out=open( devname, O_WRONLY|O_NONBLOCK, 0);
+  audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
   if(audio_out != -1)
     {
 #ifdef SNDCTL_DSP_COOKEDMODE
@@ -1058,7 +1039,7 @@
     ioctl(audio_out, SNDCTL_DSP_COOKEDMODE, &j);
 #endif
     for(nn=0; nn<80; nn++)SNDLOG"-");
-    SNDLOG"\n%s opened as %s ",devname, devmode_txt[3]);
+    SNDLOG"\n%s opened as %s ",dev_name, devmode_txt[3]);
     sndlog_sync();
     j=AFMT_U8;
     if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1)
@@ -1110,6 +1091,7 @@
       {
       SNDLOG"\nIncorrect speed response in %d  out %d",
                                                    ABOVE_MAX_SPEED, j);
+      tspeed=j;
       if(ioctl(audio_out, SNDCTL_DSP_SPEED, &j)==-1)
        {
         SNDLOG"\nioctl(SPEED) failed");
@@ -1136,7 +1118,7 @@
       goto errdev;  
       }
     sprintf(s,"%02d  %s  %7d - %7d Hz   %d Chan.   %d bit WRONLY",
-                device_no, devname,
+                device_no, dev_name,
                 dev_min_wr_speed[device_no], 
                 dev_max_wr_speed[device_no], 
                 dev_wr_channels[device_no], 
@@ -1373,20 +1355,20 @@
   {
   dev_flag[device_no]=0;
   make_devname(device_no);
-  SNDLOG"Checking %s\n",devname);
+  SNDLOG"Checking %s\n",dev_name);
   sndlog_sync();
   for(mode=0; mode<3; mode++)
     {
     k=1<<mode;
     sprintf(s,
     "Trying to open %s %s. Device defective if system hangs here. Read %s   ",
-    devname, devmode_txt[mode],logfile_name);
+    dev_name, devmode_txt[mode],logfile_name);
     sndlog_sync();
     settextcolor(12);
     lir_text(0,line+1,s);
     lir_refresh_screen();
     settextcolor(7);
-    audio_out=open( devname, devmodes[mode]|O_NONBLOCK, 0);
+    audio_out=open( dev_name, devmodes[mode]|O_NONBLOCK, 0);
     clear_lines(line+1,line+1);
     if(audio_out != -1)
       {
@@ -1395,7 +1377,7 @@
         ioctl(audio_out, SNDCTL_DSP_COOKEDMODE, &i);
       #endif
       for(nn=0; nn<80; nn++)SNDLOG"-");
-      SNDLOG"\n%s opened as %s ",devname, devmode_txt[mode]);
+      SNDLOG"\n%s opened as %s ",dev_name, devmode_txt[mode]);
       sndlog_sync();
       rdwr_fmt=16;
       rdwr_channels=0;
@@ -1465,8 +1447,8 @@
       i=0;
       while(i<MAX_LOWSPEED)
         {
-        rdwr_min_speed=low_speeds[i];
-        if(ioctl(audio_out, SNDCTL_DSP_SPEED, &rdwr_min_speed)!=-1)goto minok;
+        tspeed=rdwr_min_speed=low_speeds[i];
+        if(ioctl(audio_out, SNDCTL_DSP_SPEED, &tspeed)!=-1)goto minok;
         i++;
         }
       lirerr(1040);
@@ -1577,7 +1559,7 @@
       if( (dev_flag[device_no]&1) == 1)
         {
         sprintf(ss,"%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit",
-                    device_no,devname,
+                    device_no,dev_name,
                     dev_min_rd_speed[device_no], 
                     dev_max_rd_speed[device_no], 
                     dev_max_rd_channels[device_no], 
@@ -1588,7 +1570,7 @@
         if( (dev_flag[device_no]&2) == 2)
           {
           sprintf(ss,"%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit",
-                     device_no,devname,
+                     device_no,dev_name,
                      dev_min_wr_speed[device_no], 
                      dev_max_wr_speed[device_no], 
                      dev_wr_channels[device_no], 
@@ -1637,13 +1619,13 @@
           color=0x17;
           sprintf(&ss[maxcolumn],
                      "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,
+                      device_no,dev_name,
                       dev_min_wr_speed[device_no], 
                       dev_max_wr_speed[device_no], 
                       dev_wr_channels[device_no], 
                       dev_wr_bits[device_no],devmode_txt[1]);
           sprintf(ss,"%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,
+                      device_no,dev_name,
                       dev_min_rd_speed[device_no], 
                       dev_max_rd_speed[device_no], 
                       dev_max_rd_channels[device_no], 
@@ -1659,21 +1641,21 @@
             color=0x17;
             sprintf(&ss[2*maxcolumn],
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,
+                      device_no,dev_name,
                       dev_min_wr_speed[device_no], 
                       dev_max_wr_speed[device_no], 
                       dev_wr_channels[device_no], 
                       dev_wr_bits[device_no],devmode_txt[1]);
             sprintf(&ss[maxcolumn],
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,
+                      device_no,dev_name,
                       dev_min_rd_speed[device_no], 
                       dev_max_rd_speed[device_no], 
                       dev_max_rd_channels[device_no], 
                       dev_rd_bits[device_no],devmode_txt[0]);
             sprintf(ss,
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,
+                      device_no,dev_name,
                       dev_min_rdwr_speed[device_no], 
                       dev_max_rdwr_speed[device_no], 
                       dev_rdwr_channels[device_no], 
@@ -1688,14 +1670,14 @@
               color=0x17;
               sprintf(&ss[maxcolumn],
                         "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
-                        device_no,devname,
+                        device_no,dev_name,
                         dev_min_wr_speed[device_no], 
                         dev_max_wr_speed[device_no], 
                         dev_wr_channels[device_no], 
                         dev_wr_bits[device_no],devmode_txt[1]);
               sprintf(ss,
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s  %s",
-                        device_no,devname,
+                        device_no,dev_name,
                         dev_min_rd_speed[device_no], 
                         dev_max_rd_speed[device_no], 
                         dev_max_rd_channels[device_no], 
@@ -1707,14 +1689,14 @@
               color=0x1d;
               sprintf(&ss[maxcolumn],
                         "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s  %s",
-                        device_no,devname,
+                        device_no,dev_name,
                         dev_min_wr_speed[device_no], 
                         dev_max_wr_speed[device_no], 
                         dev_wr_channels[device_no], dev_wr_bits[device_no],
                         devmode_txt[1],devmode_txt[2]);
               sprintf(ss,
                   "%02d:%12s  %7d - %7d Hz   %d Chan.   %d bit  %s",
-                        device_no,devname,
+                        device_no,dev_name,
                         dev_min_rd_speed[device_no], 
                         dev_max_rd_speed[device_no], 
                         dev_max_rd_channels[device_no], 
@@ -1822,7 +1804,7 @@
 
 clear_screen();
 make_devname(ui.ad_device_no);
-SNDLOG"\n\n %s selected by user for input.",devname);
+SNDLOG"\n\n %s selected by user for input.",dev_name);
 SNDLOG"   dev_flag=%d",dev_flag[ui.ad_device_no]);
 sndlog_sync();
 // High end users might need two devices to read four A/D channels.
@@ -1864,7 +1846,7 @@
         clear_screen();
         SNDLOG"\nUser wants to try to open two read devices"); 
         make_devname(ui.ad_device_no);
-        audio_in=open( devname, O_RDONLY, 0);
+        audio_in=open( dev_name, O_RDONLY, 0);
         if(audio_in == -1)
           {
           lirerr(1102);
@@ -1899,7 +1881,7 @@
           }
         }
       make_devname(i);
-      audio_in2=open( devname, O_RDONLY|O_NONBLOCK, 0);
+      audio_in2=open( dev_name, O_RDONLY|O_NONBLOCK, 0);
       if(audio_in2 != -1)
         {
         #ifdef SNDCTL_DSP_COOKEDMODE
@@ -1907,9 +1889,9 @@
           ioctl(audio_in2, SNDCTL_DSP_COOKEDMODE, &k);
         #endif
         line++;
-        SNDLOG"\n%s opened as second read device",devname);
+        SNDLOG"\n%s opened as second read device",dev_name);
         sprintf(s,"%2d:%12s  %7d - %7d Hz   %d Chan.   %d bit",
-                i,devname,
+                i,dev_name,
                 dev_min_rd_speed[i], 
                 dev_max_rd_speed[i], 
                 dev_max_rd_channels[i], 
@@ -1945,7 +1927,7 @@
     {
     dev_flag[i]&=255;
     }    
-  audio_in2=open( devname, O_RDONLY|O_NONBLOCK, 0);
+  audio_in2=open( dev_name, O_RDONLY|O_NONBLOCK, 0);
   if(audio_in2 == -1)
     {
     lirerr(1172);
@@ -1968,7 +1950,7 @@
     close(audio_in2);
     goto skip_dual_devices;
     }
-  SNDLOG"\n %s is second input device.",devname);
+  SNDLOG"\n %s is second input device.",dev_name);
   ui.input_mode=TWO_CHANNELS+IQ_DATA;
   ui.rx_channels=2;
   ui.ad_channels=4;
@@ -1988,7 +1970,7 @@
   if( (1 & dev_flag[ui.ad_device_no]) != 0)
     {
 gt_rdo:;    
-    sprintf(s,"Open %s as RDONLY or RDWR? (O/W)  =>",devname);  
+    sprintf(s,"Open %s as RDONLY or RDWR? (O/W)  =>",dev_name);  
     lir_text(10,10,s);
     await_processed_keyboard();
     if(kill_all_flag) goto setad_errexit;
@@ -2010,9 +1992,9 @@
   }
 sndlog_sync();
 clear_screen();  
-sprintf(s,"For analog input: %s opened in %s mode",devname,devmode_txt[mode]);
+sprintf(s,"For analog input: %s opened in %s mode",dev_name,devmode_txt[mode]);
 lir_text(0,0,s);
-audio_in=open( devname, ui.ad_device_mode, 0);
+audio_in=open( dev_name, ui.ad_device_mode, 0);
 if(audio_in == -1)
   {
   lirerr(1038);
@@ -2108,13 +2090,16 @@
 lir_text(0,7,"to reconfigure the hardware. (Under OSS, run ossmix)");
 max=dev_max_rd_speed[ui.ad_device_no&255];
 min=dev_min_rd_speed[ui.ad_device_no&255];
+#if 0
 if(max == ABOVE_MAX_SPEED || max < 1000)
   {
   max = ABOVE_MAX_SPEED;
   speed_warning = 1;
   }
+#endif
 sprintf(s,"Select sampling speed(%d to %d)", min,max);
 lir_text(0,10,s);
+#if 0
 if(speed_warning != 0)
   {
   settextcolor(12);
@@ -2123,6 +2108,7 @@
    lir_text(0,13,"Incorrect (not supported) values may cause system to hang");
   settextcolor(7);
   }
+#endif
 column=0;
 while(s[column] != 0)column++;
 ui.input_speed=lir_get_integer(column+2, 10, 8, min,max);
@@ -2131,6 +2117,7 @@
 rdwr_max_speed=ui.input_speed;
 SNDLOG"\n%d Hz selected by user",ui.input_speed);
 clear_lines(5,10);
+ui.input_speed;
 if(ioctl(audio_in, SNDCTL_DSP_SPEED, &ui.input_speed)==-1)
   {
   lirerr(1041);
@@ -2249,7 +2236,7 @@
   goto setad_errexit;
   }
 settextcolor(12);
-sprintf(s,"Trying to read %s",devname);
+sprintf(s,"Trying to read %s",dev_name);
 lir_text(10,10,s);
 lir_text(0,12,"If you see this message for more than 2 seconds READ failed");
 lir_text(0,13,"Then try another device");
@@ -2313,7 +2300,7 @@
   }
 SNDLOG"\nRead test OK");
 clear_lines(10,13);
-sprintf(s,"Now trying to open a second device while %s is open",devname);
+sprintf(s,"Now trying to open a second device while %s is open",dev_name);
 lir_text(0,6,s);
 lir_text(0,7,"This may cause your system to hang. Try ctrlC to exit (or reboot)");
 lir_text(0,8,"Try another input device or install another sound system."); 
@@ -2326,7 +2313,7 @@
   if(read_test_ad(testbuff)!=0)goto clr_wrdev;
   make_devname(i);
   cn=0;
-  sprintf(s,"%02d:%12s",i,devname);
+  sprintf(s,"%02d:%12s",i,dev_name);
   lir_text(0,line,s);
   column=0;
   while(s[column] != 0)column++;
@@ -2338,7 +2325,7 @@
       if( (ui.input_mode&DWORD_INPUT) != 0 || ui.ad_channels > 2)
         {
         sprintf(&s[column],
-             " RDWR  useless (too many bits or channels) %d: %s",i,devname);
+             " RDWR  useless (too many bits or channels) %d: %s",i,dev_name);
         dev_flag[i]=0;
         }
       else
@@ -2356,7 +2343,7 @@
     dev_flag[i]&=0xffff-4;
     if( (dev_flag[i]&2) != 0 )
       {
-      audio_out=open( devname, O_WRONLY|O_NONBLOCK, 0);
+      audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
       if(read_test_ad(testbuff)!=0)goto clr_wrdev;
       if(audio_out != -1)
         { 
@@ -2364,7 +2351,7 @@
         j=0;
         ioctl(audio_out, SNDCTL_DSP_COOKEDMODE, &j);
 #endif
-        SNDLOG"\n%s opened as WRONLY",devname);
+        SNDLOG"\n%s opened as WRONLY",dev_name);
         sndlog_sync();
         if(ioctl(audio_in, SNDCTL_DSP_GETISPACE, &ad_info) == -1)
           {
@@ -2562,20 +2549,20 @@
   for(i=0; i<MAX_DEVNAMES; i++)
     {
     make_devname(i);
-    SNDLOG"\n%s ",devname);
+    SNDLOG"\n%s ",dev_name);
     cn=0;
-    sprintf(s,"%02d:%12s",i,devname);
+    sprintf(s,"%02d:%12s",i,dev_name);
     lir_text(0,line,s);
     column=0;
     while(s[column] != 0)column++;
-    audio_out=open( devname, O_WRONLY|O_NONBLOCK, 0);
+    audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
     if(audio_out != -1)
       { 
       #ifdef SNDCTL_DSP_COOKEDMODE
         j=0;
         ioctl(audio_out, SNDCTL_DSP_COOKEDMODE, &j);
       #endif
-      SNDLOG"\n%s opened as WRONLY with no input open.",devname);
+      SNDLOG"\n%s opened as WRONLY with no input open.",dev_name);
       sndlog_sync();
       j=AFMT_U8;
       if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1)
@@ -2727,7 +2714,7 @@
 // -------------------------------------------------------  
   }
 make_devname(ui.da_device_no);
-SNDLOG"\nUser selected %s for output.",devname);
+SNDLOG"\nUser selected %s for output.",dev_name);
 clear_sdi();
 clear_lines(6,line);
 lir_text(0,8,"Use close and reopen for D/A when a new signal is");
@@ -2762,8 +2749,8 @@
   }
 else
   {
-  audio_out=open( devname ,O_WRONLY , 0);
-  sprintf(s,"Using %s for output",devname);
+  audio_out=open( dev_name ,O_WRONLY , 0);
+  sprintf(s,"Using %s for output",dev_name);
   lir_text(0,6,s);
   if(audio_out == -1)
     {
