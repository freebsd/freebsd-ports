--- frontend/audio.c.orig	Thu Jul 25 08:42:54 2002
+++ frontend/audio.c	Wed Jan  8 20:52:34 2003
@@ -52,7 +52,7 @@
         break;
     }
     aufile->sfinfo.channels = channels;
-    aufile->sfinfo.samples  = 0;
+    aufile->sfinfo.frames  = 0;
 #ifdef _WIN32
     if(infile[0] == '-')
     {
