--- a/bsd-user/qemu.h
+++ b/bsd-user/qemu.h
@@ -50,6 +50,10 @@ struct image_info {
     abi_ulong entry;
     abi_ulong code_offset;
     abi_ulong data_offset;
+#if 1
+    abi_ulong arg_start;
+    abi_ulong arg_end;
+#endif
     int       personality;
 };
 
@@ -72,6 +76,17 @@ struct emulated_sigtable {
 typedef struct TaskState {
     struct TaskState *next;
     int used; /* non zero if used */
+#if 1
+#ifdef TARGET_ARM
+    int swi_errno;
+#endif
+#if defined(TARGET_ARM) || defined(TARGET_M68K) || defined(TARGET_UNICORE32)
+    /* Extra fields for semihosted binaries.  */
+    uint32_t heap_base;
+    uint32_t heap_limit;
+#endif
+    uint32_t stack_base;
+#endif
     struct image_info *info;
 
     struct emulated_sigtable sigtab[TARGET_NSIG];
