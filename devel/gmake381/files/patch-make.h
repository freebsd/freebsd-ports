--- make.h.orig	Wed Sep 11 18:55:44 2002
+++ make.h	Mon Oct 21 22:05:11 2002
@@ -33,7 +33,7 @@
 #  ifdef _AIX
  #pragma alloca
 #  else
-#   ifndef alloca /* predefined by HP cc +Olibcalls */
+#   if !defined (alloca) && !defined (__FreeBSD__) /* predefined by HP cc +Olibcalls, part of stdlib.h on FreeBSD */
 char *alloca ();
 #   endif
 #  endif

