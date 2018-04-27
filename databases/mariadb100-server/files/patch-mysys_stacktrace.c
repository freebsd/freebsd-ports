--- mysys/stacktrace.c.orig	2018-01-27 18:40:37 UTC
+++ mysys/stacktrace.c
@@ -34,19 +34,19 @@
 #include <execinfo.h>
 #endif
 
+#ifdef __linux__
 #define PTR_SANE(p) ((p) && (char*)(p) >= heap_start && (char*)(p) <= heap_end)
-
 static char *heap_start;
-
-#ifdef HAVE_BSS_START
 extern char *__bss_start;
-#endif
+#else
+#define PTR_SANE(p) (p)
+#endif /* __linux */
 
 void my_init_stacktrace()
 {
-#ifdef HAVE_BSS_START
+#ifdef __linux__
   heap_start = (char*) &__bss_start;
-#endif
+#endif /* __linux__ */
 }
 
 #ifdef __linux__
@@ -149,15 +149,15 @@ static int safe_print_str(const char *ad
 
 int my_safe_print_str(const char* val, int max_len)
 {
+#ifdef __linux__
   char *heap_end;
 
-#ifdef __linux__
   // Try and make use of /proc filesystem to safely print memory contents.
   if (!safe_print_str(val, max_len))
     return 0;
-#endif
 
   heap_end= (char*) sbrk(0);
+#endif
 
   if (!PTR_SANE(val))
   {
