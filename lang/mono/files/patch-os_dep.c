--- libgc/os_dep.c.orig	Wed Jul  5 17:55:43 2006
+++ libgc/os_dep.c	Sun Sep 10 11:04:32 2006
@@ -84,7 +84,7 @@
 #   define NEED_FIND_LIMIT
 # endif
 
-#if defined(FREEBSD) && (defined(I386) || defined(powerpc) || defined(__powerpc__))
+#if defined(FREEBSD) && (defined(I386) || defined(X86_64) || defined(powerpc) || defined(__powerpc__))
 #  include <machine/trap.h>
 #  if !defined(PCR)
 #    define NEED_FIND_LIMIT
@@ -1396,7 +1396,7 @@
 }
 # endif
 
-# if defined(FREEBSD) && (defined(I386) || defined(powerpc) || defined(__powerpc__)) && !defined(PCR)
+# if defined(FREEBSD) && (defined(I386) || defined(X86_64) || defined(powerpc) || defined(__powerpc__)) && !defined(PCR)
 /* Its unclear whether this should be identical to the above, or 	*/
 /* whether it should apply to non-X86 architectures.			*/
 /* For now we don't assume that there is always an empty page after	*/
