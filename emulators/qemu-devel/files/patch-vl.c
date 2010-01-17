Index: qemu/vl.c
@@ -57,6 +57,7 @@
 #include <sys/stat.h>
 #if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <libutil.h>
+#include <sys/param.h>
 #else
 #include <util.h>
 #endif
