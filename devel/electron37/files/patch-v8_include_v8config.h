--- v8/include/v8config.h.orig	2025-04-22 20:15:27 UTC
+++ v8/include/v8config.h
@@ -201,6 +201,8 @@ path. Add it with -I<path> to the command line
   && !defined(V8_TARGET_OS_FUCHSIA) \
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_LINUX) \
+  && !defined(V8_TARGET_OS_OPENBSD) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
   && !defined(V8_TARGET_OS_MACOS) \
   && !defined(V8_TARGET_OS_WIN) \
   && !defined(V8_TARGET_OS_CHROMEOS)
@@ -213,6 +215,8 @@ path. Add it with -I<path> to the command line
   || defined(V8_TARGET_OS_FUCHSIA) \
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_LINUX) \
+  || defined(V8_TARGET_OS_OPENBSD) \
+  || defined(V8_TARGET_OS_FREEBSD) \
   || defined(V8_TARGET_OS_MACOS) \
   || defined(V8_TARGET_OS_WIN) \
   || defined(V8_TARGET_OS_CHROMEOS)
@@ -236,6 +240,16 @@ path. Add it with -I<path> to the command line
 # define V8_TARGET_OS_LINUX
 #endif
 
+#ifdef V8_OS_OPENBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
+#ifdef V8_OS_FREEBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
 #ifdef V8_OS_MACOS
 # define V8_TARGET_OS_MACOS
 #endif
@@ -383,6 +397,7 @@ path. Add it with -I<path> to the command line
 #if (defined(_M_X64) || defined(__x86_64__)            /* x64 (everywhere) */  \
      || ((defined(__AARCH64EL__) || defined(_M_ARM64)) /* arm64, but ... */    \
          && !defined(_WIN32)))                         /* not on windows */    \
+     && !defined(__OpenBSD__)                          /* not on OpenBSD */    \
      && !defined(COMPONENT_BUILD)                      /* no component build */\
      && __clang_major__ >= 17                          /* clang >= 17 */
 # define V8_HAS_ATTRIBUTE_PRESERVE_MOST (__has_attribute(preserve_most))
