Index: qemu/exec.c
@@ -405,6 +405,28 @@
             exit(1);
         }
     }
+#elif defined(__FreeBSD__)
+    {
+        int flags;
+        void *addr = NULL;
+        flags = MAP_PRIVATE | MAP_ANONYMOUS;
+#if defined(__x86_64__)
+        /* FreeBSD doesn't have MAP_32BIT, use MAP_FIXED and assume
+         * 0x40000000 is free */
+        flags |= MAP_FIXED;
+        addr = (void *)0x40000000;
+        /* Cannot map more than that */
+        if (code_gen_buffer_size > (800 * 1024 * 1024))
+            code_gen_buffer_size = (800 * 1024 * 1024);
+#endif
+        code_gen_buffer = mmap(addr, code_gen_buffer_size,
+                               PROT_WRITE | PROT_READ | PROT_EXEC, 
+                               flags, -1, 0);
+        if (code_gen_buffer == MAP_FAILED) {
+            fprintf(stderr, "Could not allocate dynamic translator buffer\n");
+            exit(1);
+        }
+    }
 #else
     code_gen_buffer = qemu_malloc(code_gen_buffer_size);
     if (!code_gen_buffer) {
