--- libgc/os_dep.c.orig	Tue May  3 09:54:00 2005
+++ libgc/os_dep.c	Sat Aug  6 18:23:12 2005
@@ -80,7 +80,7 @@
 #   define NEED_FIND_LIMIT
 # endif
 
-#if defined(FREEBSD) && defined(I386)
+#if defined(FREEBSD) && (defined(I386) || defined(X86_64))
 #  include <machine/trap.h>
 #  if !defined(PCR)
 #    define NEED_FIND_LIMIT
@@ -1385,7 +1385,7 @@
 }
 # endif
 
-# if defined(FREEBSD) && defined(I386) && !defined(PCR)
+# if defined(FREEBSD) && (defined(X86_64) || defined(I386)) && !defined(PCR)
 /* Its unclear whether this should be identical to the above, or 	*/
 /* whether it should apply to non-X86 architectures.			*/
 /* For now we don't assume that there is always an empty page after	*/
