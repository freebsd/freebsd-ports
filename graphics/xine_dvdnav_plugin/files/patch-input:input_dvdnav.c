--- input/input_dvdnav.c.orig	Fri Apr 26 04:10:57 2002
+++ input/input_dvdnav.c	Tue May 21 02:24:15 2002
@@ -38,7 +38,6 @@
 #include <string.h>
 #include <errno.h>
 
-#include <sys/mount.h>
 #include <sys/wait.h>
 
 #include <sys/poll.h>
@@ -347,17 +346,17 @@
   }
   if (1) {
     int fd, i;
-    off64_t off;
+    off_t off;
     uint8_t data[DVD_VIDEO_LB_LEN];
 
     /* Read DVD name */
     fd=open(intended_dvd_device, O_RDONLY);
     if (fd > 0) { 
-      off = lseek64( fd, 32 * (int64_t) DVD_VIDEO_LB_LEN, SEEK_SET );
-      if( off == ( 32 * (int64_t) DVD_VIDEO_LB_LEN ) ) {
+      off = lseek( fd, 32 * DVD_VIDEO_LB_LEN, SEEK_SET );
+      if( off == ( 32 * DVD_VIDEO_LB_LEN ) ) {
         off = read( fd, data, DVD_VIDEO_LB_LEN ); 
         close(fd);
-        if (off == ( (int64_t) DVD_VIDEO_LB_LEN )) {
+        if (off == ( DVD_VIDEO_LB_LEN )) {
           fprintf( stderr, "DVD Title: ");
           for(i=25; i < 73; i++ ) {
             if((data[i] == 0)) break;
