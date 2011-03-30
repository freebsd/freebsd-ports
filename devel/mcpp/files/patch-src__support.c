--- ./src/support.c.orig	2008-06-10 10:32:33.000000000 +0200
+++ ./src/support.c	2011-03-30 19:57:37.000000000 +0200
@@ -188,7 +188,7 @@
     size_t      length
 )
 {
-    if (mem_buf_p->bytes_avail < length) {  /* Need to allocate more memory */
+    if (mem_buf_p->bytes_avail < length + 1) {  /* Need to allocate more memory */
         size_t size = MAX( BUF_INCR_SIZE, length);
 
         if (mem_buf_p->buffer == NULL) {            /* 1st append   */
@@ -1722,6 +1722,8 @@
                     sp -= 2;
                     while (*sp != '\n')     /* Until end of line    */
                         mcpp_fputc( *sp++, OUT);
+                    mcpp_fputc( '\n', OUT);
+                    wrong_line = TRUE;
                 }
                 goto  end_line;
             default:                        /* Not a comment        */
