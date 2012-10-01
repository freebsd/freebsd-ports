--- src/xsane.h.o	2012-10-01 11:12:56.549589382 -0400
+++ src/xsane.h	2012-10-01 11:12:40.660589178 -0400
@@ -251,7 +251,7 @@
 # elif defined(HAVE_OS2_H)
 #  define DEFAULT_BROWSER "netscape"
 # else
-#  define DEFAULT_BROWSER "netscape"
+#  define DEFAULT_BROWSER "xdg-open"
 # endif
 #endif
 
