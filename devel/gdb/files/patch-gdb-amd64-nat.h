--- gdb/amd64-nat.h.orig	2011-09-23 01:36:54.874780473 +0100
+++ gdb/amd64-nat.h	2011-09-23 01:28:46.964218514 +0100
@@ -50,9 +50,4 @@
 extern void amd64_collect_native_gregset (const struct regcache *regcache,
 					  void *gregs, int regnum);
 
-/* Create a prototype *BSD/amd64 target.  The client can override it
-   with local methods.  */
-
-extern struct target_ops *amd64bsd_target (void);
-
 #endif /* amd64-nat.h */
