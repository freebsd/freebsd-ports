--- include/my_stacktrace.h.orig	2024-12-16 09:20:55 UTC
+++ include/my_stacktrace.h
@@ -45,7 +45,7 @@
   _WIN32 - Windows
   HAVE_EXT_BACKTRACE - Unixes without backtrace(3)
 */
-#if defined(HAVE_BACKTRACE) || defined(_WIN32) || defined(HAVE_EXT_BACKTRACE)
+#if (defined(HAVE_BACKTRACE) || defined(_WIN32)) && (defined(__aarch64__) || defined(__amd64__) || defined(__i386__))
 #define HAVE_STACKTRACE 1
 void my_init_stacktrace();
 void my_print_stacktrace(const uchar *stack_bottom, ulong thread_stack);
