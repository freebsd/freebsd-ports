--- setad.c.orig	Tue May 18 09:43:30 2004
+++ setad.c	Thu Jul  8 14:17:52 2004
@@ -16,11 +16,11 @@
 #define ABOVE_MAX_SPEED 768000
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
 
@@ -36,7 +36,7 @@
 sync();
 }
 
-void make_devname(int n)
+void make_dev_name(int n)
 {
 int k,num,m;
 if(n < 0)end_program(9235);
@@ -47,13 +47,13 @@
 m=num/10;
 if(m > 0)
   {
-  devname[k]=m+'0';
+  dev_name[k]=m+'0';
   k++;
   }
-devname[k]=num-m*10+'0';
-if(devname[k]<'0')devname[k]=0;
+dev_name[k]=num-m*10+'0';
+if(dev_name[k]<'0')dev_name[k]=0;
 k++;
-devname[k]=0;  
+dev_name[k]=0;  
 }
 
 void set_da_parms(void)
@@ -148,14 +148,14 @@
 if(disksave_flag == 2 || network_flag == 2)return;
 if( (ui.input_mode&NO_DUPLEX) != 0 && audio_out != -1)return;
 if(  (audio_in) != -1)end_program(1000);
-make_devname(ui.ad_device_no&255);
-audio_in=open( devname ,ui.ad_device_mode , 0);
+make_dev_name(ui.ad_device_no&255);
+audio_in=open( dev_name ,ui.ad_device_mode , 0);
 if(audio_in == -1)end_program(1007);
 if(ui.ad_device_no > 255)
   {
   i=ui.ad_device_no/255-1;
-  make_devname(i);
-  audio_in2=open( devname ,ui.ad_device_mode , 0);
+  make_dev_name(i);
+  audio_in2=open( dev_name ,ui.ad_device_mode , 0);
   if(audio_in2 == -1)end_program(1174);
   }
 if(ui.ad_frag != 0)
@@ -238,8 +238,8 @@
   if(disksave_flag >=2)
     {
     if(audio_in != -1)end_program(9865);
-    make_devname(ui.ad_device_no&255);
-    audio_out=open( devname ,O_WRONLY , 0);
+    make_dev_name(ui.ad_device_no&255);
+    audio_out=open( dev_name ,O_WRONLY , 0);
     if(audio_out == -1)end_program(1086);
     goto set_da;
     }
@@ -275,8 +275,8 @@
   }
 else
   {
-  make_devname(ui.da_device_no);
-  audio_out=open( devname ,O_WRONLY|O_NONBLOCK , 0);
+  make_dev_name(ui.da_device_no);
+  audio_out=open( dev_name ,O_WRONLY|O_NONBLOCK , 0);
   if(audio_out == -1)end_program(1017);
 set_da:;
 // Set a small fragment size so we can stop playing quickly.
@@ -397,24 +397,24 @@
 for(device_no=0; device_no<MAX_DEVNAMES; device_no++)
   {
   dev_flag[device_no]=0;
-  make_devname(device_no);
-  fprintf(sndlog,"Checking %s\n",devname);
+  make_dev_name(device_no);
+  fprintf(sndlog,"Checking %s\n",dev_name);
   flush_sync();
   for(mode=0; mode<3; mode++)
     {
     k=1<<mode;
     sprintf(s,
     "Trying to open %s %s. Device defective if system hangs here. Read %s   ",
-    devname, devmode_txt[mode],logfile_name);
+    dev_name, devmode_txt[mode],logfile_name);
     flush_sync();
     settextcolor(12);
     xytext(0,line+1,s);
     settextcolor(7);
-    audio_out=open( devname, devmodes[mode]|O_NONBLOCK, 0);
+    audio_out=open( dev_name, devmodes[mode]|O_NONBLOCK, 0);
     if(audio_out != -1)
       {
       for(nn=0; nn<80; nn++)fprintf(sndlog,"-");
-      fprintf(sndlog,"\n%s opened as %s ",devname, devmode_txt[mode]);
+      fprintf(sndlog,"\n%s opened as %s ",dev_name, devmode_txt[mode]);
       flush_sync();
       rdwr_fmt=16;
       rdwr_channels=0;
@@ -575,7 +575,7 @@
       if( (dev_flag[device_no]&1) == 1)
         {
         sprintf(ss,"\n%02d:%12s  %7d Hz   %d Chan.   %d bit",
-                    device_no,devname,dev_rd_speed[device_no], 
+                    device_no,dev_name,dev_rd_speed[device_no], 
                     dev_rd_channels[device_no], 
                     dev_rd_bits[device_no]);
         }
@@ -584,7 +584,7 @@
         if( (dev_flag[device_no]&2) == 2)
           {
           sprintf(ss,"\n%02d:%12s  %7d Hz   %d Chan.   %d bit",
-                     device_no,devname,dev_wr_speed[device_no], 
+                     device_no,dev_name,dev_wr_speed[device_no], 
                      dev_wr_channels[device_no], 
                      dev_wr_bits[device_no]);
           }
@@ -631,11 +631,11 @@
           color=0x17;
           sprintf(&ss[maxcolumn],
                      "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,dev_wr_speed[device_no], 
+                      device_no,dev_name,dev_wr_speed[device_no], 
                       dev_wr_channels[device_no], 
                       dev_wr_bits[device_no],devmode_txt[1]);
           sprintf(ss,"\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,dev_rd_speed[device_no], 
+                      device_no,dev_name,dev_rd_speed[device_no], 
                       dev_rd_channels[device_no], 
                       dev_rd_bits[device_no],devmode_txt[0]);
           }
@@ -649,17 +649,17 @@
             color=0x17;
             sprintf(&ss[2*maxcolumn],
                   "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,dev_wr_speed[device_no], 
+                      device_no,dev_name,dev_wr_speed[device_no], 
                       dev_wr_channels[device_no], 
                       dev_wr_bits[device_no],devmode_txt[1]);
             sprintf(&ss[maxcolumn],
                   "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,dev_rd_speed[device_no], 
+                      device_no,dev_name,dev_rd_speed[device_no], 
                       dev_rd_channels[device_no], 
                       dev_rd_bits[device_no],devmode_txt[0]);
             sprintf(ss,
                   "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s",
-                      device_no,devname,dev_rdwr_speed[device_no], 
+                      device_no,dev_name,dev_rdwr_speed[device_no], 
                       dev_rdwr_channels[device_no], 
                       dev_rdwr_bits[device_no],devmode_txt[2]);
             }
@@ -672,12 +672,12 @@
               color=0x17;
               sprintf(&ss[maxcolumn],
                         "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s",
-                        device_no,devname,dev_wr_speed[device_no], 
+                        device_no,dev_name,dev_wr_speed[device_no], 
                         dev_wr_channels[device_no], 
                         dev_wr_bits[device_no],devmode_txt[1]);
               sprintf(ss,
                   "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s  %s",
-                          device_no,devname,dev_rd_speed[device_no], 
+                          device_no,dev_name,dev_rd_speed[device_no], 
                         dev_rd_channels[device_no], dev_rd_bits[device_no],
                             devmode_txt[0],devmode_txt[2]);
               }
@@ -686,12 +686,12 @@
               color=0x1d;
               sprintf(&ss[maxcolumn],
                         "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s  %s",
-                        device_no,devname,dev_wr_speed[device_no], 
+                        device_no,dev_name,dev_wr_speed[device_no], 
                         dev_wr_channels[device_no], dev_wr_bits[device_no],
                         devmode_txt[1],devmode_txt[2]);
               sprintf(ss,
                   "\n%02d:%12s  %7d Hz   %d Chan.   %d bit  %s",
-                          device_no,devname,dev_rd_speed[device_no], 
+                          device_no,dev_name,dev_rd_speed[device_no], 
                         dev_rd_channels[device_no], dev_rd_bits[device_no],
                             devmode_txt[0]);
               }
@@ -777,8 +777,8 @@
     }
   }
 vga_clear();
-make_devname(ui.ad_device_no);
-fprintf(sndlog,"\n\n %s selected by user for input.",devname);
+make_dev_name(ui.ad_device_no);
+fprintf(sndlog,"\n\n %s selected by user for input.",dev_name);
 fprintf(sndlog,"   dev_flag=%d",dev_flag[ui.ad_device_no]);
 flush_sync();
 // High end users might need two devices to read four A/D channels.
@@ -819,8 +819,8 @@
         if(vga_inkey != 'Y')goto gt_dual;  
         vga_clear();
         fprintf(sndlog,"\nUser wants to try to open two read devices"); 
-        make_devname(ui.ad_device_no);
-        audio_in=open( devname, O_RDONLY, 0);
+        make_dev_name(ui.ad_device_no);
+        audio_in=open( dev_name, O_RDONLY, 0);
         if(audio_in == -1)end_program(1102);
 // Check for DSP_CAP_TRIGGER capability
         if(ioctl(audio_in, SNDCTL_DSP_GETCAPS,&caps) == -1)end_program(1182);
@@ -834,14 +834,14 @@
         if(ioctl(audio_in, SNDCTL_DSP_CHANNELS, &j) == -1)end_program(1185);  
         if(j != 2)end_program(1186);
         }
-      make_devname(i);
-      audio_in2=open( devname, O_RDONLY|O_NONBLOCK, 0);
+      make_dev_name(i);
+      audio_in2=open( dev_name, O_RDONLY|O_NONBLOCK, 0);
       if(audio_in2 != -1)
         {
         line++;
-        fprintf(sndlog,"\n%s opened as second read device",devname);
+        fprintf(sndlog,"\n%s opened as second read device",dev_name);
         sprintf(s,"\n%02d:%12s  %7d Hz   %d Chan.   %d bit",
-                i,devname,dev_rd_speed[i], dev_rd_channels[i], 
+                i,dev_name,dev_rd_speed[i], dev_rd_channels[i], 
                 dev_rd_bits[i]);
         xytext(0,line,s);
         close(audio_in2);
@@ -866,13 +866,13 @@
     goto get_addev2;
     }
 // We store the second A/D device in the second byte of ad_device_no
-  make_devname(i);
+  make_dev_name(i);
   ui.ad_device_no+=256*(i+1);
   for(i=0; i<MAX_DEVNAMES; i++)
     {
     dev_flag[i]&=255;
     }    
-  audio_in2=open( devname, O_RDONLY|O_NONBLOCK, 0);
+  audio_in2=open( dev_name, O_RDONLY|O_NONBLOCK, 0);
   if(audio_in2 == -1)end_program(1172);
 // Check for DSP_CAP_TRIGGER capability
   if(ioctl(audio_in2, SNDCTL_DSP_GETCAPS,&caps) == -1)end_program(1182);
@@ -883,7 +883,7 @@
     close(audio_in2);
     goto skip_dual_devices;
     }
-  fprintf(sndlog,"\n %s is second input device.",devname);
+  fprintf(sndlog,"\n %s is second input device.",dev_name);
   ui.input_mode=TWO_CHANNELS+IQ_DATA;
   ui.rx_channels=2;
   ui.ad_channels=4;
@@ -894,7 +894,7 @@
   }
 // Now that we decided what device to use for input, open it and let
 // the user decide how to use it.
-make_devname(ui.ad_device_no);
+make_dev_name(ui.ad_device_no);
 flush_sync();
 ui.ad_device_mode=O_RDONLY;
 mode=0;
@@ -903,7 +903,7 @@
   if( (1 & dev_flag[ui.ad_device_no]) != 0)
     {
 gt_rdo:;    
-    sprintf(s,"Open %s as RDONLY or RDWR? (O/W)\n=>",devname);  
+    sprintf(s,"Open %s as RDONLY or RDWR? (O/W)\n=>",dev_name);  
     xytext(10,10,s);
     vga_inkey=vga_getkey();
     clean_vga_inkey();
@@ -925,9 +925,9 @@
   }
 flush_sync();
 vga_clear();  
-sprintf(s,"For analog input: %s opened in %s mode",devname,devmode_txt[mode]);
+sprintf(s,"For analog input: %s opened in %s mode",dev_name,devmode_txt[mode]);
 xytext(0,0,s);
-audio_in=open( devname, ui.ad_device_mode, 0);
+audio_in=open( dev_name, ui.ad_device_mode, 0);
 if(audio_in == -1)end_program(1038);
 j=dev_rd_channels[ui.ad_device_no];
 xytext(0,10,"Select radio interface:");
@@ -1123,7 +1123,7 @@
 
 
 settextcolor(12);
-sprintf(s,"Trying to read %s",devname);
+sprintf(s,"Trying to read %s",dev_name);
 xytext(10,10,s);
 xytext(0,12,"If you see this message for more than 2 seconds READ failed");
 xytext(0,13,"Then try another device");
@@ -1176,7 +1176,7 @@
   }
 fprintf(sndlog,"\nRead test OK");
 for(i=10; i<14; i++)xytext(0,i,ss);
-sprintf(s,"Now trying to open a second device while %s is open",devname);
+sprintf(s,"Now trying to open a second device while %s is open",dev_name);
 xytext(0,6,s);
 xytext(0,7,"This may cause your system to hang. Try ctrlC to exit (or reboot)");
 xytext(0,8,"Try another input device or install another sound system."); 
@@ -1192,9 +1192,9 @@
      read(audio_in, testbuff, 1024);
      if(ioctl(audio_in,SNDCTL_DSP_GETISPACE,&ad_info) == -1)end_program(1093);
      }
-  make_devname(i);
+  make_dev_name(i);
   cn=0;
-  sprintf(s,"%02d:%12s",i,devname);
+  sprintf(s,"%02d:%12s",i,dev_name);
   xytext(0,line,s);
   column=0;
   while(s[column] != 0)column++;
@@ -1206,7 +1206,7 @@
       if( (ui.input_mode&DWORD_INPUT) != 0 || ui.ad_channels > 2)
         {
         sprintf(&s[column],
-             " RDWR  useless (too many bits or channels) %d: %s",i,devname);
+             " RDWR  useless (too many bits or channels) %d: %s",i,dev_name);
         dev_flag[i]=0;
         }
       else
@@ -1224,10 +1224,10 @@
     dev_flag[i]&=0xffff-4;
     if( (dev_flag[i]&2) != 0 )
       {
-      audio_out=open( devname, O_WRONLY|O_NONBLOCK, 0);
+      audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
       if(audio_out != -1)
         { 
-        fprintf(sndlog,"\n%s opened as WRONLY",devname);
+        fprintf(sndlog,"\n%s opened as WRONLY",dev_name);
         flush_sync();
         if(ioctl(audio_in, SNDCTL_DSP_GETISPACE, 
                                           &ad_info) == -1)end_program(1094);
@@ -1380,17 +1380,17 @@
   line=0;
   for(i=0; i<MAX_DEVNAMES; i++)
     {
-    make_devname(i);
-    fprintf(sndlog,"\n%s ",devname);
+    make_dev_name(i);
+    fprintf(sndlog,"\n%s ",dev_name);
     cn=0;
-    sprintf(s,"%02d:%12s",i,devname);
+    sprintf(s,"%02d:%12s",i,dev_name);
     xytext(0,line,s);
     column=0;
     while(s[column] != 0)column++;
-    audio_out=open( devname, O_WRONLY|O_NONBLOCK, 0);
+    audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
     if(audio_out != -1)
       { 
-      fprintf(sndlog,"\n%s opened as WRONLY with no input open.",devname);
+      fprintf(sndlog,"\n%s opened as WRONLY with no input open.",dev_name);
       flush_sync();
       j=AFMT_U8;
       if(ioctl(audio_out, SNDCTL_DSP_SETFMT, &j) == -1)
@@ -1528,8 +1528,8 @@
   ui.da_device_no=j;
   if( (6 & dev_flag[ui.da_device_no]) == 0) goto get_dadev;
   }
-make_devname(ui.da_device_no);
-fprintf(sndlog,"\nUser selected %s for output.",devname);  
+make_dev_name(ui.da_device_no);
+fprintf(sndlog,"\nUser selected %s for output.",dev_name);  
 for(i=6; i<=line; i++)xytext(0,i,ss);  
 xytext(0,8,"Use close and reopen for D/A when");
 xytext(0,9,"a new signal is selected? (Y/N)");
@@ -1563,8 +1563,8 @@
   }
 else
   {
-  audio_out=open( devname ,O_WRONLY , 0);
-  sprintf(s,"\nUsing %s for output",devname);
+  audio_out=open( dev_name ,O_WRONLY , 0);
+  sprintf(s,"\nUsing %s for output",dev_name);
   xytext(0,6,s);
   if(audio_out == -1)end_program(1068);
   da_wrbuf = NULL;
