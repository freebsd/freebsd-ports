--- ./YGP/Tests/Thread.cpp.orig	Sun Jun  4 01:32:35 2006
+++ ./YGP/Tests/Thread.cpp	Sun Aug 20 14:16:06 2006
@@ -30,7 +30,6 @@
 #include <ygp-cfg.h>
 
 #if defined HAVE__SLEEP
-#  define sleep      _sleep
 #endif
 
 
