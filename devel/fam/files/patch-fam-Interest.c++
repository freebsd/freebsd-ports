diff -ruN fam/Interest.c++ fam/Interest.c++
--- fam/Interest.c++	Mon Apr 29 02:26:54 2002
+++ fam/Interest.c++	Sat Jun  8 16:31:07 2002
@@ -25,7 +25,9 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/param.h>
-#include <sys/sysmacros.h>
+#if !defined(__FreeBSD__)
+#  include <sys/sysmacros.h>
+#endif
 
 #ifdef HAVE_IRIX_XTAB_VERIFICATION
 #include <stdio.h>
