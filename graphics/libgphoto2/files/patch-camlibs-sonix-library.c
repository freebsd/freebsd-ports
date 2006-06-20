--- camlibs/sonix/library.c.orig	Wed Apr 19 03:54:18 2006
+++ camlibs/sonix/library.c	Wed Jun 21 00:12:06 2006
@@ -41,7 +41,7 @@
 #else
 #  define _(String) (String)
 #  define N_(String) (String)
-#  define ngettext(String1,String2,Count) ((Count==1)?String1:String)
+#  define ngettext(String1,String2,Count) ((Count==1)?String1:String2)
 #endif
 
 #include <gphoto2-port.h>
