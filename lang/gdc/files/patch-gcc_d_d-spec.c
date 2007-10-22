--- gcc/d/d-spec.c.orig	2007-10-16 20:24:22.000000000 +0900
+++ gcc/d/d-spec.c	2007-10-16 20:29:07.000000000 +0900
@@ -46,6 +46,10 @@
 #define MATH_LIBRARY_PROFILE "-lm"
 #endif
 
+#ifndef LIBSTDCXX
+#define LIBSTDCXX "-lstdc++"
+#endif
+
 #ifndef LIBPHOBOS
 #define LIBPHOBOS "-lgphobos"
 #endif
@@ -295,7 +299,7 @@
     /* There is one extra argument added here for the runtime
        library: -lgphobos.  The -pthread argument is added by
        setting need_pthreads. */
-    num_args = argc + added + need_math + shared_libgcc + (library > 0 ? 1 : 0) + 1;
+    num_args = argc + added + need_math + shared_libgcc + (library > 0 ? 2 : 0) + 1;
     arglist = xmalloc (num_args * sizeof (char *));
 
     i = 0;
@@ -353,6 +357,8 @@
     /* Add `-lstdc++' if we haven't already done so.  */
     if (library > 0)
 	{
+	    arglist[j++] = LIBSTDCXX;
+	    added_libraries++;
 	    arglist[j++] = saw_profile_flag ? LIBPHOBOS_PROFILE : LIBPHOBOS;
 	    added_libraries++;
 	    need_pthreads = 1;
