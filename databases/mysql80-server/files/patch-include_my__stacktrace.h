--- include/my_stacktrace.h.orig	2020-01-23 19:43:07.769584000 +0100
+++ include/my_stacktrace.h	2020-01-23 19:43:48.684042000 +0100
@@ -43,7 +43,7 @@
   HAVE_BACKTRACE - Linux, FreeBSD, OSX, Solaris
   _WIN32 - Windows
 */
-#if defined(HAVE_BACKTRACE) || defined(_WIN32)
+#if (defined(HAVE_BACKTRACE) || defined(_WIN32)) && (defined(__aarch64__) || defined(__amd64__) || defined(__i386__))
 #define HAVE_STACKTRACE 1
 void my_init_stacktrace();
 void my_print_stacktrace(uchar *stack_bottom, ulong thread_stack);
