
$FreeBSD$

--- src/s/freebsd.h.orig
+++ src/s/freebsd.h
@@ -61,3 +61,19 @@
 
 /* Use the GC_MAKE_GCPROS_NOOPS (see lisp.h) method for marking the stack.  */
 #define GC_MARK_STACK 	GC_MAKE_GCPROS_NOOPS
+
+#define INTERRUPT_INPUT
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
