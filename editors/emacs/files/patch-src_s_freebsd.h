
$FreeBSD$

--- src/s/freebsd.h.orig
+++ src/s/freebsd.h
@@ -58,3 +58,17 @@
 /* Tell that garbage collector that setjmp is known to save all
    registers relevant for conservative garbage collection in the jmp_buf.  */
 #define GC_SETJMP_WORKS 1
+
+#define PTY_ITERATION	int i; for (i = 0; i < 1; i++)
+#define PTY_NAME_SPRINTF	/* none */
+#define PTY_TTY_NAME_SPRINTF	/* none */
+#define PTY_OPEN						\
+  do								\
+    {								\
+      int slave;						\
+      if (openpty (&fd, &slave, pty_name, NULL, NULL) == -1)	\
+	fd = -1;						\
+      else							\
+	emacs_close (slave);					\
+    }								\
+  while (0)
