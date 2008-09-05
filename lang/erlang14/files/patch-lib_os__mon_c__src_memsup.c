
$FreeBSD$

--- lib/os_mon/c_src/memsup.c.orig
+++ lib/os_mon/c_src/memsup.c
@@ -404,7 +404,7 @@
 #endif
 
 #if defined(BSD4_4)
-static void
+static int
 get_extended_mem_bsd4(memory_ext *me) {
     struct vmtotal vt;
     long pgsz;
