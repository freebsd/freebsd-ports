--- coregrind/m_debuglog.c.orig	2019-01-08 21:35:12.953178000 +0400
+++ coregrind/m_debuglog.c	2019-01-08 21:36:10.940827000 +0400
@@ -482,8 +482,8 @@
       "popq  %%r15\n"           /* restore r15 */
       "addq  $256, %%rsp\n"     /* restore stack ptr */
       : /*wr*/
-      : /*rd*/    "g" (block)
-      : /*trash*/ "rax", "rdi", "rsi", "rdx", "memory", "cc"
+      : /*rd*/    "r" (block)
+      : /*trash*/ "rax", "rdi", "rsi", "rdx", "memory", "cc", "rcx", "r11"
    );
    if (block[0] < 0) 
       block[0] = -1;
