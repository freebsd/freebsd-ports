
$FreeBSD$

--- cd.c.orig	Mon May 19 15:44:40 2003
+++ cd.c	Mon May 19 15:53:44 2003
@@ -98,8 +98,16 @@
   cd_play.end_s=cdinfo.s_sec[cdinfo.l_track-1];
   cd_play.end_f=cdinfo.s_frame[cdinfo.l_track-1];
   
-  if(ioctl (cd_fd, CDIOCPLAYMSF, (char *) &cd_play)<0)
-    per();
+  if(ioctl (cd_fd, CDIOCPLAYMSF, (char *) &cd_play)<0) {
+    /* Hack for IDE CD-ROMs */
+    if (cd_play.start_s < 2) {
+      cd_play.start_s=2;
+      if(ioctl (cd_fd, CDIOCPLAYMSF, (char *) &cd_play)<0)
+        per();
+    } else
+      per();
+  }
+  cdinfo.pause=0;
 }
 
 /* Skips one track forward */
@@ -111,7 +119,7 @@
 /* Quess */
 void prev(void)
 {
-  if(cdinfo.c_sec<1)
+  if(cdinfo.c_sec<4)
     play_track(cdinfo.c_track-1);
   else play_track(cdinfo.c_track);
 }
@@ -141,17 +149,59 @@
   }
 }
 
+/* Softly pauses the cd, or unpauses, as appropriate */
+void cdsoftpause(void)
+{
+  struct ioc_vol real_vol, cur_vol;
+  int i;
+
+  if(ioctl(cd_fd,CDIOCGETVOL,(char *) &real_vol)) per();
+  cur_vol = real_vol;
+
+  if(cdinfo.pause){
+    message="continue";
+    memset (cur_vol.vol, 0, sizeof(cur_vol.vol));
+    if(ioctl(cd_fd,CDIOCSETVOL,(char *) &cur_vol)) per();
+    if(ioctl(cd_fd,CDIOCRESUME)<0) per(); else cdinfo.pause=0;
+    for (i=0; i<20; usleep(21), i++) {
+      cur_vol.vol[0] += (real_vol.vol[0] / 20);
+      cur_vol.vol[1] += (real_vol.vol[1] / 20);
+      cur_vol.vol[2] += (real_vol.vol[2] / 20);
+      cur_vol.vol[3] += (real_vol.vol[3] / 20);
+      if(ioctl(cd_fd,CDIOCSETVOL,(char *) &cur_vol)) per();
+    }
+    if(ioctl(cd_fd,CDIOCSETVOL,(char *) &real_vol)) per();
+  }
+  else {
+    message="pause";
+    for (i=0; i<20; usleep(21), i++) {
+      cur_vol.vol[0] -= (real_vol.vol[0] / 20);
+      cur_vol.vol[1] -= (real_vol.vol[1] / 20);
+      cur_vol.vol[2] -= (real_vol.vol[2] / 20);
+      cur_vol.vol[3] -= (real_vol.vol[3] / 20);
+      if(ioctl(cd_fd,CDIOCSETVOL,(char *) &cur_vol)) per();
+    }
+    if(ioctl (cd_fd, CDIOCPAUSE)<0) per(); else cdinfo.pause=1;
+    if(ioctl (cd_fd, CDIOCSETVOL,(char *) &real_vol)) per();
+  }
+}
+  
 /* Huge kludge */
-void ff(void)
+void ff(int n_times)
 {
+  int secs;
   struct ioc_play_msf cd_play;
 
-  if(cdinfo.c_seca%60+5>=60){
-    cd_play.start_s=((cdinfo.c_seca%60)+5)%60;
+  secs=4*n_times;
+
+  if (secs > 59) secs=59;
+
+  if(cdinfo.c_seca%60+secs>=60){
+    cd_play.start_s=((cdinfo.c_seca%60)+secs)%60;
     cd_play.start_m=cdinfo.c_seca/60+1;
   }
   else {
-    cd_play.start_s=(cdinfo.c_seca%60)+5;
+    cd_play.start_s=(cdinfo.c_seca%60)+secs;
     cd_play.start_m=cdinfo.c_seca/60;
   }
   cd_play.start_f=1;
@@ -160,19 +210,25 @@
   cd_play.end_f=cdinfo.s_frame[cdinfo.l_track-1];
 
   if(ioctl(cd_fd,CDIOCPLAYMSF,(char *) &cd_play)<0) per();
+  cdinfo.pause=0;
 }
 
 /* Hi mom!! */
-void rew(void)
+void rew(int n_times)
 {
+  int secs;
   struct ioc_play_msf cd_play;
 
-  if(cdinfo.c_seca%60-5<0){
-    cd_play.start_s=((cdinfo.c_seca%60)-5)+60;
+  secs=4*n_times;
+
+  if (secs > 59) secs=59;
+
+  if(cdinfo.c_seca%60-secs<0){
+    cd_play.start_s=((cdinfo.c_seca%60)-secs)+60;
     cd_play.start_m=cdinfo.c_seca/60-1;
   }
   else {
-    cd_play.start_s=(cdinfo.c_seca%60)-5;
+    cd_play.start_s=(cdinfo.c_seca%60)-secs;
     cd_play.start_m=cdinfo.c_seca/60;
   }
   cd_play.start_f=1;
@@ -181,6 +237,7 @@
   cd_play.end_f=cdinfo.s_frame[cdinfo.l_track-1];
 
   if(ioctl(cd_fd,CDIOCPLAYMSF,(char *) &cd_play)<0) per();
+  cdinfo.pause=0;
 }
 
 /* Spit cd out */
@@ -192,6 +249,7 @@
     per();
   close(cd_fd);
   cdinfo.eject=1;
+  cdinfo.pause=1;
 }
 
 
