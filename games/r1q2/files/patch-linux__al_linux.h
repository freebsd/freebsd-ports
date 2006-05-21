--- ./linux/al_linux.h.orig	Sat Sep 24 16:18:00 2005
+++ ./linux/al_linux.h	Wed May 17 22:28:37 2006
@@ -23,7 +23,7 @@
 #define __AL_LINUX_H__
 
 
-#ifndef __linux__
+#ifndef __unix__
 #error "You should not be including this file on this platform"
 #endif
 
