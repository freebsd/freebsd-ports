--- ../ex/ex_script.c.orig
+++ ../ex/ex_script.c
@@ -19,7 +19,7 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/queue.h>
-#ifdef HAVE_SYS_SELECT_H
+#if 0
 #include <sys/select.h>
 #endif
 #include <sys/stat.h>
