--- sound/mixer.h.orig	Wed Jan  1 13:21:10 2003
+++ sound/mixer.h	Wed Jan  1 13:21:41 2003
@@ -25,6 +25,8 @@
 
 #include <stdio.h>
 
+#undef USE_MAD
+
 #ifdef USE_MAD
 #include <mad.h>
 #endif
