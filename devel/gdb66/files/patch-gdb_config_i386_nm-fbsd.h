--- gdb/config/i386/nm-fbsd.h	Sat Jul 21 13:16:44 2001
+++ gdb/config/i386/nm-fbsd.h	Mon Jun  3 10:04:54 2002
@@ -28,6 +28,10 @@
 
 #include "i386/nm-i386.h"
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 /* Provide access to the i386 hardware debugging registers.  */
 
 #define I386_DR_LOW_SET_CONTROL(control) \
@@ -148,5 +152,32 @@
 #define ld_2		d_sdt
 
 #endif /* !SVR4_SHARED_LIBS */
+
+extern int kernel_debugging;
+extern int kernel_writablecore;
+
+#if __FreeBSD_version >= 500032
+#define ADDITIONAL_OPTIONS \
+       {"kernel", no_argument, &kernel_debugging, 1}, \
+       {"k", no_argument, &kernel_debugging, 1}, \
+       {"wcore", no_argument, &kernel_writablecore, 1}, \
+       {"w", no_argument, &kernel_writablecore, 1},
+
+#define ADDITIONAL_OPTION_HELP \
+       "\
+  --kernel           Enable kernel debugging.\n\
+  --wcore            Make core file writable (only works for /dev/mem).\n\
+                     This option only works while debugging a kernel !!\n\
+"
+
+#define DEFAULT_PROMPT kernel_debugging?"(kgdb) ":"(gdb) "
+
+/* misuse START_PROGRESS to test whether we're running as kgdb */   
+/* START_PROGRESS is called at the top of main */
+#undef START_PROGRESS
+#define START_PROGRESS(STR,N) \
+  if (!strcmp(STR, "kgdb")) \
+     kernel_debugging = 1;
+#endif
 
 #endif /* NM_FBSD_H */
