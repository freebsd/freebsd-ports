--- ./newlib/libc/sys/psp/crt0.c.orig	2012-01-25 19:33:12.000000000 +0000
+++ ./newlib/libc/sys/psp/crt0.c	2012-01-25 19:33:12.000000000 +0000
@@ -0,0 +1,3 @@
+/* The real crt0.c lives in PSPSDK. */
+
+void _start() { }
