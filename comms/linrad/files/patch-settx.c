--- settx.c.orig	Wed Jun  7 15:31:03 2006
+++ settx.c	Wed Jun  7 15:32:01 2006
@@ -21,7 +21,7 @@
 #define LEVEL_METER_X 65
 
 extern void make_devname(int device_no);
-extern char devname[];
+extern char dev_name[];
 extern char *devmode_txt[3];
 
 #if SND_DEV == 1
@@ -73,7 +73,7 @@
 int i,j;
 float t1;
 make_devname(tx.ad_device_no);
-tx_audio_in=open( devname, O_RDONLY, 0);
+tx_audio_in=open( dev_name, O_RDONLY, 0);
 if(tx_audio_in == -1)lirerr(991111);
 i=AFMT_S16_LE;
 #ifdef AFMT_S32_LE
@@ -107,7 +107,7 @@
 int i,j;
 float t1;
 make_devname(tx.da_device_no);
-tx_audio_out=open( devname, O_WRONLY|O_NONBLOCK, 0);
+tx_audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
 if(tx_audio_out == -1)lirerr(231111);
 i=AFMT_S16_LE;
 #ifdef AFMT_S32_LE
@@ -300,11 +300,11 @@
     make_devname(device_no);
       {
       sprintf(s,"Trying to open %s %s. Device defective if system hangs here.",
-                                           devname, devmode_txt[1]);
+                                           dev_name, devmode_txt[1]);
       settextcolor(12);
       lir_text(0,line+1,s);
       settextcolor(7);
-      tx_audio_out=open( devname, O_WRONLY|O_NONBLOCK, 0);
+      tx_audio_out=open( dev_name, O_WRONLY|O_NONBLOCK, 0);
       if(tx_audio_out != -1)
         {
         line++;
@@ -374,7 +374,7 @@
           }
         dev_min_speed[device_no]=rdwr_speed;
         settextcolor(7);  
-        sprintf(s,"  %02d  %s     ",device_no,devname);
+        sprintf(s,"  %02d  %s     ",device_no,dev_name);
         lir_text(0,line,s);
         sprintf(s,"%s   ",devmode_txt[1]);
         if(rdwr_channels==3)
@@ -516,7 +516,7 @@
   }
 clear_screen();
 make_devname(tx.da_device_no);
-sprintf(s,"Tx output: %s, %d channel(s), %d bits, %d Hz",devname,
+sprintf(s,"Tx output: %s, %d channel(s), %d bits, %d Hz",dev_name,
                       tx.output_channels,tx.output_bytes<<3,tx.output_speed);
 settextcolor(14);
 lir_text(15,0,s);
@@ -578,11 +578,11 @@
     make_devname(device_no);
       {
       sprintf(s,"Trying to open %s %s. Device defective if system hangs here.",
-                                           devname, devmode_txt[0]);
+                                           dev_name, devmode_txt[0]);
       settextcolor(12);
       lir_text(0,line+1,s);
       settextcolor(7);
-      tx_audio_in=open( devname, O_RDONLY|O_NONBLOCK, 0);
+      tx_audio_in=open( dev_name, O_RDONLY|O_NONBLOCK, 0);
       if(tx_audio_in != -1)
         {
         line++;
@@ -652,7 +652,7 @@
           }
         dev_min_speed[device_no]=rdwr_speed;
         settextcolor(7);  
-        sprintf(s,"  %02d  %s     ",device_no,devname);
+        sprintf(s,"  %02d  %s     ",device_no,dev_name);
         lir_text(0,line,s);
         sprintf(s,"%s   ",devmode_txt[0]);
         if(rdwr_channels==3)
@@ -774,7 +774,7 @@
 clear_screen();
 make_devname(tx.ad_device_no);
 
-sprintf(s,"Microphone input: %s, %d channel(s), %d bits, %d Hz",devname,
+sprintf(s,"Microphone input: %s, %d channel(s), %d bits, %d Hz",dev_name,
                       tx.input_channels,tx.input_bytes<<3,tx.input_speed);
 settextcolor(14);
 lir_text(15,0,s);
