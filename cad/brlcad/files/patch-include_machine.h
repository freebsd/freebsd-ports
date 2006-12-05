Index: include/machine.h
===================================================================
RCS file: /cvsroot/brlcad/brlcad/include/machine.h,v
retrieving revision 14.20
diff -u -r14.20 machine.h
--- include/machine.h	18 Sep 2006 05:24:07 -0000	14.20
+++ include/machine.h	14 Nov 2006 18:00:33 -0000
@@ -611,7 +611,8 @@
 
 #endif
 
-#if defined(__sparc64__)
+/* TODO: should this be looking for solaris/sunos tags? */
+#if defined(__sparc64__) && !defined(__FreeBSD__)
 /********************************
  *                              *
  *      Sparc 64       		*
@@ -702,11 +703,11 @@
 # define LOCAL		auto		/* static|auto, for serial|parallel cpu */
 
 /* amd64 */
-# if defined(__x86_64__)
+# if defined(__x86_64__) || defined(__sparc64__) || defined(__ia64__)
 #  define BITV_SHIFT	6
 #  define MAX_PSW		256
 /* ia32 */
-# elif !defined(__ia64__) && !defined(__x86_64__) && !defined(__sparc64__)
+# else
 #  define BITV_SHIFT	5
 #  define MAX_PSW	16
 # endif
