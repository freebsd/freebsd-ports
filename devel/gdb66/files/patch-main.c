--- gdb/main.c.orig	Thu Apr 15 22:40:39 2004
+++ gdb/main.c	Thu Apr 15 22:47:51 2004
@@ -66,6 +66,12 @@
 /* Whether dbx commands will be handled */
 int dbx_commands = 0;
 
+#ifdef KGDB
+/* Kernel debugging support.  */
+int kernel_debugging;
+int kernel_writablecore;
+#endif
+
 /* System root path, used to find libraries etc.  */
 char *gdb_sysroot = 0;
 
@@ -311,6 +317,12 @@
       {"statistics", no_argument, 0, OPT_STATISTICS},
       {"write", no_argument, &write_files, 1},
       {"args", no_argument, &set_args, 1},
+#ifdef KGDB
+      {"kernel", no_argument, &kernel_debugging, 1},
+      {"k", no_argument, &kernel_debugging, 1},
+      {"wcore", no_argument, &kernel_writablecore, 1},
+      {"w", no_argument, &kernel_writablecore, 1},
+#endif
       {0, no_argument, 0, 0}
     };
 
@@ -857,6 +869,11 @@
   --interpreter=INTERP\n\
                      Select a specific interpreter / user interface\n\
 "), stream);
+#ifdef KGDB
+  fputs_unfiltered (_("\
+  --kernel           Enable kernel debugging.\n\
+"), stream);
+#endif
   fputs_unfiltered (_("\
   --mapped           Use mapped symbol files if supported on this system.\n\
   --nw		     Do not use a window interface.\n\
@@ -874,6 +891,12 @@
 #if defined(TUI)
   fputs_unfiltered (_("\
   --tui              Use a terminal user interface.\n\
+"), stream);
+#endif
+#ifdef KGDB
+  fputs_unfiltered (_("\
+  --wcore            Make core file writable (only works for /dev/mem).\n\
+                     This option only works while debugging a kernel !!\n\
 "), stream);
 #endif
   fputs_unfiltered (_("\
