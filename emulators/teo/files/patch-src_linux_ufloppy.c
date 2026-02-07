# HG changeset patch
# User François Mouret
# Date 1544541950 -3600
#      Tue Dec 11 16:25:50 2018 +0100
# Node ID e49c586caa6bfd5cbc710fbbef05cf6f3c361fcd
# Parent  e5023114c1b22b12a07de65eaa3460cae578ec49
Avoid floppy reactions for non Linux systems (thanks to Thomas Bernard)

--- src/linux/ufloppy.c.orig	2017-11-03 16:40:23 UTC
+++ src/linux/ufloppy.c
@@ -44,6 +44,7 @@
  */
 
 
+#if defined(linux)
 #ifndef SCAN_DEPEND
    #include <stdio.h>
    #include <string.h>
@@ -404,3 +405,18 @@ void ufloppy_Exit (void)
     }
 }
 
+#else
+
+/* for non linux systems, such as FreeBSD, etc. */
+
+int ufloppy_Init (int to_drive_type[4], int enable_write)
+{
+    return 0;
+}
+
+void ufloppy_Exit (void)
+{
+}
+
+#endif
+
