--- elftoaout.c~	Thu Jul 10 16:48:06 1997
+++ elftoaout.c	Fri Jul  3 09:36:09 1998
@@ -9,7 +9,16 @@
 #include <linux/elf.h>
 #define ELFDATA2MSB   2
 #else
-#include <sys/elf.h>
+#include <elf.h>
+#include <sys/elf32.h>
+#include <sys/elf64.h>
+#endif
+
+#ifndef PT_LOPROC
+#define PT_LOPROC 0x70000000
+#endif
+#ifndef PT_HIPROC
+#define PT_HIPROC 0x7fffffff
 #endif
 
 #define swab16(x)  (((x)<<8&0xFF00)|((x)>>8&0x00FF))
