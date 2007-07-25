--- src/Headers/constants.h.orig	2004-08-01 03:04:28.000000000 +0800
+++ src/Headers/constants.h	2007-07-25 21:58:56.000000000 +0800
@@ -101,7 +101,7 @@
 # define DEFAULT_SYSTEMDIR "/os2/"
 # else                            
 /*@constant observer char *DEFAULT_SYSTEMDIR; @*/
-# define DEFAULT_SYSTEMDIR "/usr/"
+# define DEFAULT_SYSTEMDIR "/usr/include/:/usr/lib/:%%PREFIX%%/include/:%%PREFIX%%/lib/"
 # endif
 
 /*@constant char DEFAULT_COMMENTCHAR; @*/
