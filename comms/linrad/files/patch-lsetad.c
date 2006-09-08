--- lsetad.c.orig	Tue Aug 15 15:27:44 2006
+++ lsetad.c	Thu Sep  7 17:52:30 2006
@@ -87,10 +87,9 @@
 void display_sdi(void)
 {
 FILE *sdifile;
-int  ch_cnt;
+char *p;
 char ch_read[80];
 char work_line [80];
-int  work_line_pos ; 
 int  sdi_screen_line_counter; 
 char sdi_intro_msg [26]= "SOUND DRIVER INFORMATION:" ;
 char sdi_error_msg [46]= "No OSS or ALSA sound-driver information found";
@@ -111,55 +110,42 @@
 // if OSS not active, try  ALSA
 if (sdifile==NULL)
   {
-  strcpy (sndstat_filename,"/proc/asound/oss/sndstat");   
-  sdifile=fopen (sndstat_filename,"r"); 
+    strcpy (sndstat_filename,"/proc/asound/oss/sndstat");   
+    sdifile=fopen (sndstat_filename,"r"); 
   }
-if (sdifile==NULL) 
+if (sdifile!=NULL) 
   {
-  settextcolor(LIGHT_RED); 
-  lir_text ( 80, sdi_screen_line_counter++, sdi_error_msg);
-  fprintf (sndlog,"\n%s",sdi_error_msg ); 
-  goto display_sdi_x;
-  }
-fprintf (sndlog,"\n(output of 'cat %s' command): \n\n",sndstat_filename );
-memset (work_line, '\0',sizeof(work_line));
-work_line_pos =0; 
-settextcolor(LIGHT_GREEN);
-ch_cnt=fread(ch_read,1,1,sdifile);
-while (ch_cnt== 1)
-  {
-// check if work_line is ready for output processing
-  if ((ch_read[0] =='\n') || (work_line_pos == 78))
-    {
-// display work_line only if it is not blank
-// and there are enough lines available on the screen
-// and there are at least 40 characters available on a line
-    if ((work_line_pos >1) && 
-       ( sdi_screen_line_counter < screen_last_line) &&  
-       ((screen_last_col - 40)>= 80))
-      {
-      if (ch_read[0] !='\n') work_line[work_line_pos]=ch_read[0]; 
-      sdi_screen_line_counter++;
-      lir_text (80, sdi_screen_line_counter, work_line);
-      }
-// write  to soundboard_init.log
-    if (ch_read[0] =='\n')  work_line[work_line_pos]=ch_read[0]; 
-    if (ch_read[0] !='\n') 
-      {
-// this is a truncated line. Add newline character
-      work_line[work_line_pos]=ch_read[0]; 
-      work_line[work_line_pos+1]='\n';
-      }
-    fprintf (sndlog,"%s",work_line); 
-    memset (work_line, '\0',sizeof(work_line));   
-    work_line_pos=-1;
-    }
-  work_line[work_line_pos]=ch_read[0]; 
-  work_line_pos++;
-  ch_cnt=fread(ch_read,1,1,sdifile);
+    fprintf (sndlog,"\n(output of 'cat %s' command): \n\n",sndstat_filename );
+    settextcolor(LIGHT_GREEN);
+    while(fgets(work_line, sizeof(work_line)-1, sdifile) != NULL)
+      {
+	// check if work_line is ready for output processing
+	if((p = strchr(work_line, '\n')) != NULL)
+	  *p = '\0';
+	if (ch_read[0] != '\0')
+	  {
+	    // display work_line only if it is not blank
+	    // and there are enough lines available on the screen
+	    // and there are at least 40 characters available on a line
+	    if (sdi_screen_line_counter < screen_last_line &&  
+		(screen_last_col - 40)>= 80)
+	      {
+		sdi_screen_line_counter++;
+		lir_text (80, sdi_screen_line_counter, work_line);
+	      }
+	    // write  to soundboard_init.log
+	    fprintf (sndlog,"%s\n",work_line); 
+	  }
+      }
+    fclose(sdifile);
+  }
+else
+  {
+    settextcolor(LIGHT_RED); 
+    lir_text ( 80, sdi_screen_line_counter++, sdi_error_msg);
+    fprintf (sndlog,"\n%s",sdi_error_msg ); 
   }
 fclose(sdifile);
-display_sdi_x:;
 fprintf(sndlog,sndlog_sep);
 fflush(sndlog);
 }
@@ -525,6 +511,11 @@
 if(i&AFMT_S16_LE)ui.max_output_bytes=2;
 ui.max_output_speed=ABOVE_MAX_SPEED;
 ui.min_output_speed=1;
+//
+// To allow a separate #ifdef __FreeBSD__
+// - Diane Bruce VA3DB, Sept 6, 2006
+//
+#ifdef __linux__
 if(ioctl(audio_out, SNDCTL_DSP_SPEED, &ui.max_output_speed) == -1)
   {
   lirerr(1072);
@@ -535,6 +526,7 @@
   lirerr(1073);
   return;
   }
+#endif
 if(ui.max_output_speed==ABOVE_MAX_SPEED || 
    ui.min_output_speed <= 1 ||
    ui.max_output_speed < ui.min_output_speed)
@@ -1077,6 +1069,11 @@
     SNDLOG"\nNo of output channels= %d",j);
     sndlog_sync();
     dev_wr_channels[device_no]=j;
+//
+// To allow a separate #ifdef __FreeBSD__
+// - Diane Bruce VA3DB, Sept 6, 2006
+//
+#ifdef __linux__
     j=ABOVE_MAX_SPEED;
     if(ioctl(audio_out, SNDCTL_DSP_SPEED, &j) == -1 || j==ABOVE_MAX_SPEED)
       {
@@ -1103,6 +1100,29 @@
     dev_min_wr_speed[device_no]=j;
     SNDLOG"\nMin output speed %d", dev_min_wr_speed[device_no]);
     sndlog_sync();
+#endif
+//
+// This code finds min max speed of sound card for FreeBSD
+// It probably works for other BSDs as well
+// Diane Bruce, db@db.net VA3DB
+// Sept 7, 2006
+//
+#ifdef __FreeBSD__
+{
+  snd_capabilities capab;
+  int status;
+  bzero((void *)&capab, sizeof(capab));
+  status = ioctl(audio_out, AIOGCAP, &capab);
+  if (status < 0)
+    goto errdev;
+  dev_min_wr_speed[device_no] = capab.rate_min;
+  dev_max_wr_speed[device_no]= capab.rate_max;
+  ui.min_output_speed = capab.rate_min;
+  ui.max_output_speed = capab.rate_max;
+  SNDLOG"\nMax output speed %d", dev_max_wr_speed[device_no]);
+  SNDLOG"\nMin output speed %d", dev_min_wr_speed[device_no]);
+}
+#endif
     if(close(audio_out)==-1)
       {
       goto errdev;  
@@ -1425,6 +1445,11 @@
         SNDLOG"\nMax no of channels = %d",m);
         }  
       sndlog_sync();
+//
+// To allow a separate #ifdef __FreeBSD__
+// - Diane Bruce VA3DB, Sept 6, 2006
+//
+#ifdef __linux__
 // Find maximum speed
       rdwr_max_speed=ABOVE_MAX_SPEED;
       if(ioctl(audio_out, SNDCTL_DSP_SPEED, &rdwr_max_speed)==-1)
@@ -1444,6 +1469,27 @@
       lirerr(1040);
       goto setad_errexit;
 minok:;
+#endif
+//
+// This code finds min max speed of sound card for FreeBSD
+// It probably works for other BSDs as well
+// Diane Bruce, db@db.net VA3DB
+// Sept 7, 2006
+//
+#ifdef __FreeBSD__
+{
+  snd_capabilities capab;
+  int status;
+  bzero((void *)&capab, sizeof(capab));
+  status = ioctl(audio_out, AIOGCAP, &capab);
+  if (status < 0)
+    goto setad_errexit;
+  rdwr_min_speed = capab.rate_min;
+  rdwr_max_speed = capab.rate_max;
+  SNDLOG"\nMin output speed %d", rdwr_min_speed);
+  SNDLOG"\nMax output speed %d", rdwr_max_speed);
+}
+#endif
       SNDLOG"\nMin sampling speed = %d Hz",rdwr_min_speed);
       sndlog_sync();
       if(mode != 1)
