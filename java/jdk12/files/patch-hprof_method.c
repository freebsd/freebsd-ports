$FreeBSD$

--- ../../src/share/tools/hprof/hprof_method.c	26 Oct 1999 20:42:59 -0000	1.3
+++ ../../src/share/tools/hprof/hprof_method.c	20 Feb 2003 07:11:17 -0000
@@ -123,7 +123,7 @@
     int stack_depth;
     int trace_depth;
     unsigned int hash = 0;
-#if defined __GNUC__ && (__GNUC__ == 2 && __GNUC_MINOR__ >= 8)
+#if defined(__GNUC__) && ((__GNUC__ == 2 && __GNUC_MINOR__ >= 8) || (__GNUC__ >= 3))
     jlong total_time = 0;
 #endif
     int i;
