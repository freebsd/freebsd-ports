--- src/alloc.h.orig	Sun May 12 22:53:00 2002
+++ src/alloc.h	Sun May 12 22:53:27 2002
@@ -39,22 +39,6 @@
 #define alloca _alloca
 #endif
 
-#ifndef __GNUC__
-# if HAVE_ALLOCA_H
-#  include <alloca.h>
-# else
-#  ifdef _AIX
-# pragma alloca
-#  else
-#   ifndef alloca               /* predefined by HP cc +Olibcalls */
-char *alloca ();
-#   endif
-#  endif
-# endif
-#else
-# include <alloca.h>
-#endif
-
 #define wave_alloca alloca
 
 #endif
