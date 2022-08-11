--- v8/include/v8config.h.orig	2022-06-19 00:44:37 UTC
+++ v8/include/v8config.h
@@ -183,6 +183,8 @@ path. Add it with -I<path> to the command line
   && !defined(V8_TARGET_OS_FUCHSIA) \
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_LINUX) \
+  && !defined(V8_TARGET_OS_OPENBSD) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
   && !defined(V8_TARGET_OS_MACOS) \
   && !defined(V8_TARGET_OS_WIN)
 #  error No known target OS defined.
@@ -194,6 +196,8 @@ path. Add it with -I<path> to the command line
   || defined(V8_TARGET_OS_FUCHSIA) \
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_LINUX) \
+  || defined(V8_TARGET_OS_OPENBSD) \
+  || defined(V8_TARGET_OS_FREEBSD) \
   || defined(V8_TARGET_OS_MACOS) \
   || defined(V8_TARGET_OS_WIN)
 #  error A target OS is defined but V8_HAVE_TARGET_OS is unset.
@@ -214,6 +218,16 @@ path. Add it with -I<path> to the command line
 
 #ifdef V8_OS_LINUX
 # define V8_TARGET_OS_LINUX
+#endif
+
+#ifdef V8_OS_OPENBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
+#ifdef V8_OS_FREEBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
 #endif
 
 #ifdef V8_OS_MACOS
