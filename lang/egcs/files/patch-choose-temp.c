--- gcc/choose-temp.c.orig	1999/08/26 09:26:40	1.1.1.1
+++ gcc/choose-temp.c	1999/10/02 21:50:07	1.2
@@ -22,6 +22,8 @@
 /* This file lives in at least two places: libiberty and gcc.
    Don't change one without the other.  */
 
+/* $from_FreeBSD: src/contrib/gcc/choose-temp.c,v 1.2 1999/10/02 21:50:07 obrien Exp $ */
+
 #if defined (IN_GCC) || defined (HAVE_CONFIG_H)
 #include "config.h"
 #endif
@@ -120,13 +122,14 @@
   base = try (getenv ("TMP"), base);
   base = try (getenv ("TEMP"), base);
 
+  base = try (tmp, base);
+
 #ifdef P_tmpdir
   base = try (P_tmpdir, base);
 #endif
 
-  /* Try /usr/tmp, then /tmp.  */
+  /* Try /usr/tmp even though it usually doesn't exist on FreeBSD.  */
   base = try (usrtmp, base);
-  base = try (tmp, base);
  
   /* If all else fails, use the current directory!  */
   if (base == 0)
@@ -166,13 +169,14 @@
   base = try (getenv ("TMP"), base);
   base = try (getenv ("TEMP"), base);
 
+  base = try (tmp, base);
+
 #ifdef P_tmpdir
   base = try (P_tmpdir, base);
 #endif
 
-  /* Try /usr/tmp, then /tmp.  */
+  /* Try /usr/tmp even though it usually doesn't exist on FreeBSD.  */
   base = try (usrtmp, base);
-  base = try (tmp, base);
  
   /* If all else fails, use the current directory!  */
   if (base == 0)
