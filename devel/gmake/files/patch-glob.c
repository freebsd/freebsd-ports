--- glob/glob.c.orig	Wed Sep 25 03:11:43 2002
+++ glob/glob.c	Wed Sep 25 03:15:32 2002
@@ -215,13 +215,13 @@
 #  ifdef HAVE_ALLOCA_H
 #   include <alloca.h>
 #  else	/* Not HAVE_ALLOCA_H.  */
-#   ifndef _AIX
+#   if !defined (_AIX) && !defined (__FreeBSD__)
 #    ifdef WINDOWS32
 #     include <malloc.h>
 #    else
 extern char *alloca ();
 #    endif /* WINDOWS32 */
-#   endif /* Not _AIX.  */
+#   endif /* Not _AIX && not __FreeBSD__.  */
 #  endif /* sparc or HAVE_ALLOCA_H.  */
 # endif	/* GCC.  */
 

