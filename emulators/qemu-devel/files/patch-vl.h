Index: qemu/vl.h
@@ -73,6 +73,10 @@
 #define PRIo64 "I64o"
 #endif
 
+#ifndef ENOMEDIUM
+#define ENOMEDIUM 4097
+#endif
+
 #ifdef QEMU_TOOL
 
 /* we use QEMU_TOOL in the command line tools which do not depend on
