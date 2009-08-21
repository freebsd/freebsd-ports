--- newlib/libc/sys/psp/crt0.c.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/crt0.c	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,3 @@
+/* The real crt0.c lives in PSPSDK. */
+
+void _start() { }
