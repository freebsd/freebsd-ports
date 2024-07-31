--- include/my_stacktrace.h.orig	2024-07-12 19:15:25 UTC
+++ include/my_stacktrace.h
@@ -44,7 +44,7 @@
   HAVE_BACKTRACE - Linux, FreeBSD, OSX, Solaris
   _WIN32 - Windows
 */
-#if defined(HAVE_BACKTRACE) || defined(_WIN32)
+#if (defined(HAVE_BACKTRACE) || defined(_WIN32)) && (defined(__aarch64__) || defined(__amd64__) || defined(__i386__))
 #define HAVE_STACKTRACE 1
 void my_init_stacktrace();
 void my_print_stacktrace(const uchar *stack_bottom, ulong thread_stack);
