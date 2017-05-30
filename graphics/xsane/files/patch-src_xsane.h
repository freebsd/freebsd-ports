--- src/xsane.h.orig	2013-05-22 21:43:46 UTC
+++ src/xsane.h
@@ -251,7 +251,7 @@
 # elif defined(HAVE_OS2_H)
 #  define DEFAULT_BROWSER "netscape"
 # else
-#  define DEFAULT_BROWSER "netscape"
+#  define DEFAULT_BROWSER "xdg-open"
 # endif
 #endif
 
