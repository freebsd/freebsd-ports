--- dlxsim/tcl/glob.c.orig	Sun Sep 22 09:40:54 2002
+++ dlxsim/tcl/glob.c	Sun Sep 22 09:43:49 2002
@@ -122,9 +122,8 @@
 #define direct dirent
 #define DP_NAMELEN(x) strlen ((x)->d_name)
 #else
-#include <sys/dir.h>
+#include <dirent.h>
 #include <strings.h>
-extern bcopy ();
 #endif  /* USG */
 #endif  /* USG_OLD */
 
@@ -341,7 +340,7 @@
     };
 
   DIR *d;
-  register struct direct *dp;
+  register struct dirent *dp;
   struct globval *lastlink;
   register struct globval *nextlink;
   register char *nextname;
