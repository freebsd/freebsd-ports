Index: qemu/vl.c
@@ -57,6 +57,7 @@
 #include <sys/stat.h>
 #if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <libutil.h>
+#include <sys/param.h>
 #else
 #include <util.h>
 #endif
@@ -4782,6 +4783,10 @@
 
 #endif
 
+#if !defined(CONFIG_USER_ONLY)
+void io_mem_init(void);
+#endif
+
 int main(int argc, char **argv, char **envp)
 {
 #ifdef CONFIG_GDBSTUB
@@ -5621,6 +5626,10 @@
 #ifdef CONFIG_KQEMU
     if (smp_cpus > 1)
         kqemu_allowed = 0;
+    if (kqemu_allowed && ram_size > (1536 << 20)) {
+        fprintf(stderr, "qemu: at most 1536 MB RAM can be simulated with kqemu\n");
+        exit(1);
+    }
 #endif
     if (qemu_init_main_loop()) {
         fprintf(stderr, "qemu_init_main_loop failed\n");
@@ -5715,6 +5724,9 @@
     if (ram_size == 0)
         ram_size = DEFAULT_RAM_SIZE * 1024 * 1024;
 
+    /* init the dynamic translator */
+    cpu_exec_init_all(tb_size * 1024 * 1024);
+
 #ifdef CONFIG_KQEMU
     /* FIXME: This is a nasty hack because kqemu can't cope with dynamic
        guest ram allocation.  It needs to go away.  */
@@ -5727,9 +5739,9 @@
         }
     }
 #endif
-
-    /* init the dynamic translator */
-    cpu_exec_init_all(tb_size * 1024 * 1024);
+#if !defined(CONFIG_USER_ONLY)
+    io_mem_init();
+#endif
 
     bdrv_init();
     dma_helper_init();
Index: qemu/exec.c
@@ -179,7 +179,7 @@
 static PhysPageDesc **l1_phys_map;
 
 #if !defined(CONFIG_USER_ONLY)
-static void io_mem_init(void);
+void io_mem_init(void);
 
 /* io memory support */
 CPUWriteMemoryFunc *io_mem_write[IO_MEM_NB_ENTRIES][4];
@@ -503,7 +503,7 @@
     code_gen_alloc(tb_size);
     code_gen_ptr = code_gen_buffer;
     page_init();
-#if !defined(CONFIG_USER_ONLY)
+#if 0 && !defined(CONFIG_USER_ONLY)
     io_mem_init();
 #endif
 }
@@ -2993,7 +2993,7 @@
     return -1;
 }
 
-static void io_mem_init(void)
+void io_mem_init(void)
 {
     int i;
 
