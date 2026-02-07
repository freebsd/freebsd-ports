--- server/ptrace.c.orig
+++ server/ptrace.c
@@ -291,12 +291,40 @@
 /* read a long from a thread address space */
 static int read_thread_long( struct thread *thread, void *addr, unsigned long *data )
 {
+#if defined(__FreeBSD__) && defined(__x86_64__)
+
+    int lo, hi;
+
+    errno = 0;
+
+    lo = ptrace(PTRACE_PEEKDATA, get_ptrace_pid(thread), (caddr_t)addr, 0);
+    if (lo == -1 && errno)
+    {
+      *data = -1;
+      file_set_error();
+      return -1;
+    }
+
+    hi = ptrace(PTRACE_PEEKDATA, get_ptrace_pid(thread), (caddr_t)addr + 4, 0);
+    if (hi == -1 && errno)
+    {
+      *data = -1;
+      file_set_error();
+      return -1;
+    }
+
+    *data = hi;
+    *data = (*data << 32) + lo;
+
+    return 0;
+#else
     errno = 0;
     *data = ptrace( PTRACE_PEEKDATA, get_ptrace_pid(thread), (caddr_t)addr, 0 );
     if ( *data == -1 && errno)
     {
         file_set_error();
         return -1;
     }
     return 0;
+#endif
 }
@@ -322,8 +350,18 @@
         if (read_thread_long( thread, addr, &old_data ) == -1) return -1;
         data = (data & mask) | (old_data & ~mask);
     }
+
+#if defined(__FreeBSD__) && defined(__x86_64__)
+    if ((res = ptrace(PTRACE_POKEDATA, get_ptrace_pid(thread), (caddr_t)addr,     data))       == -1 ||
+        (res = ptrace(PTRACE_POKEDATA, get_ptrace_pid(thread), (caddr_t)addr + 4, data >> 32)) == -1)
+    {
+        file_set_error();
+    }
+#else
     if ((res = ptrace( PTRACE_POKEDATA, get_ptrace_pid(thread), (caddr_t)addr, data )) == -1)
         file_set_error();
+#endif
+
     return res;
 }
