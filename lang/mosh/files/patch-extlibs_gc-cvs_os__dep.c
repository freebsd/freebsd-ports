--- extlibs/gc-cvs/os_dep.c.orig	2020-08-24 13:59:02 UTC
+++ extlibs/gc-cvs/os_dep.c
@@ -889,6 +889,8 @@ GC_INNER word GC_page_size = 0;
   /* Some tools to implement HEURISTIC2 */
 #   define MIN_PAGE_SIZE 256    /* Smallest conceivable page size, bytes */
 
+    GC_INNER JMP_BUF GC_jmp_buf;
+
     /*ARGSUSED*/
     STATIC void GC_fault_handler(int sig)
     {
