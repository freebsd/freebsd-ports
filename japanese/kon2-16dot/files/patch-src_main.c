--- src/main.c.orig	1997-01-24 09:36:48.000000000 +0900
+++ src/main.c	2012-05-10 00:14:28.933551605 +0900
@@ -29,12 +29,46 @@
 #include <stdlib.h>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#include <err.h>
+#include <osreldate.h>
+#if __FreeBSD_version >= 410000
+#  include      <sys/consio.h>
+#  include      <sys/kbio.h>
+#else
+#  include      <machine/console.h>
+#endif
+#endif	/* __FreeBSD__ */
+
 #include <getcap.h>
 
 #include <version.h>
 #include <term.h>
 
-void main(int argc, const char *argv[])
+/* handler for atexit() */
+static void
+reset_text_mode(void)
+{
+    int mode;
+
+#if defined(__FreeBSD__)
+    if (ioctl(0, KDGETMODE, &mode) == -1)
+        warn("ioctl(0, KDGETMODE)");
+    else if (mode != KD_TEXT) {
+        ioctl(0, KDSETMODE, KD_TEXT);
+    }
+
+#elif defined(__NetBSD__)
+    if (ioctl(0, WSDISPLAYIO_GMODE, &mode) == -1)
+        warn("ioctl(0, WSDISPLAYIO_GMODE)");
+    else if (mode != WSDISPLAYIO_MODE_EMUL) {
+	mode = WSDISPLAYIO_MODE_EMUL;
+	ioctl(0, WSDISPLAYIO_SMODE, &mode);
+    }
+#endif /* __NetBSD__ */
+}
+
+int main(int argc, const char *argv[])
 {
     char	*p;
 
@@ -43,6 +77,7 @@
 	fprintf(stderr, "can not get I/O permissions.\n");
 	exit(EXIT_FAILURE);
     }
+    atexit(reset_text_mode);
     ChangeNewConsole();
     TermInit(argc - 1, argv + 1);
     if (ReadConfig(CONFIG_NAME) < 0) {
