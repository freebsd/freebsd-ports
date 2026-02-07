--- src/print_mem.c.orig	2021-11-09 07:27:11 UTC
+++ src/print_mem.c
@@ -7,17 +7,21 @@
 #include <yajl/yajl_version.h>
 #include "i3status.h"
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
+
 #define MAX_DECIMALS 4
 #define STRING_SIZE ((sizeof "1023. TiB") + MAX_DECIMALS)
 
 #define BINARY_BASE 1024UL
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 static const char *const iec_symbols[] = {"B", "KiB", "MiB", "GiB", "TiB"};
 #define MAX_EXPONENT ((sizeof iec_symbols / sizeof *iec_symbols) - 1)
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 /*
  * Prints the given amount of bytes in a human readable manner.
  *
@@ -42,7 +46,7 @@ static int print_percentage(char *outwalk, float perce
 }
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 /*
  * Convert a string to its absolute representation based on the total
  * memory of `mem_total`.
@@ -89,11 +93,10 @@ void print_memory(memory_ctx_t *ctx) {
 void print_memory(memory_ctx_t *ctx) {
     char *outwalk = ctx->buf;
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     const char *selected_format = ctx->format;
     const char *output_color = NULL;
 
-    int unread_fields = 6;
     unsigned long ram_total;
     unsigned long ram_free;
     unsigned long ram_available;
@@ -101,6 +104,8 @@ void print_memory(memory_ctx_t *ctx) {
     unsigned long ram_cached;
     unsigned long ram_shared;
 
+#if defined(__linux__)
+    int unread_fields = 6;
     FILE *file = fopen("/proc/meminfo", "r");
     if (!file) {
         goto error;
@@ -130,7 +135,7 @@ void print_memory(memory_ctx_t *ctx) {
     if (unread_fields > 0) {
         goto error;
     }
-
+    
     // Values are in kB, convert them to B.
     ram_total *= 1024UL;
     ram_free *= 1024UL;
@@ -138,6 +143,25 @@ void print_memory(memory_ctx_t *ctx) {
     ram_buffers *= 1024UL;
     ram_cached *= 1024UL;
     ram_shared *= 1024UL;
+#endif
+#if defined(__FreeBSD__)
+    size_t len;
+    unsigned long active_mem;
+    len = sizeof(unsigned long);
+    ram_total = ram_free = ram_cached = ram_buffers = ram_shared =  0;
+    sysctlbyname("hw.physmem", &ram_total, &len, NULL, 0);
+    sysctlbyname("hw.usermem", &ram_available, &len, NULL, 0);
+    int page_size = getpagesize();
+    sysctlbyname("vm.stats.vm.v_cache_count", &ram_cached, &len, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_buffer_count", &ram_buffers, &len, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_wire_count", &ram_shared, &len, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_active_count", &active_mem, &len, NULL, 0);
+    sysctlbyname("vm.stats.vm.v_free_count", &ram_free, &len, NULL, 0);
+    ram_cached *= page_size;
+    ram_buffers *= page_size;
+    ram_shared *= page_size;
+    ram_free *= page_size;
+#endif
 
     unsigned long ram_used;
     if (BEGINS_WITH(ctx->memory_used_method, "memavailable")) {
@@ -211,9 +235,11 @@ void print_memory(memory_ctx_t *ctx) {
     OUTPUT_FULL_TEXT(ctx->buf);
 
     return;
+#if defined(__linux__)
 error:
     OUTPUT_FULL_TEXT("can't read memory");
     fputs("i3status: Cannot read system memory using /proc/meminfo\n", stderr);
+#endif
 #else
     OUTPUT_FULL_TEXT("");
     fputs("i3status: Memory status information is not supported on this system\n", stderr);
