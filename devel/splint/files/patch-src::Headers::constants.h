--- src/Headers/constants.h.orig	Wed Oct 30 16:08:45 2002
+++ src/Headers/constants.h	Wed Oct 30 16:09:42 2002
@@ -97,7 +97,7 @@
 # define PPMRCODE "@@MR@@"  
 
 /*@constant observer char *DEFAULT_SYSTEMDIR; @*/
-# define DEFAULT_SYSTEMDIR "/usr/"
+# define DEFAULT_SYSTEMDIR "/usr/include/:/usr/lib/:%%PREFIX%%/include/:%%PREFIX%%/lib/"
 
 /*@constant char DEFAULT_COMMENTCHAR; @*/
 # define DEFAULT_COMMENTCHAR '@'
