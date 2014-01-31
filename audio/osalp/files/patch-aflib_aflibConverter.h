--- ./aflib/aflibConverter.h.orig	2014-01-30 14:55:43.000000000 +0100
+++ ./aflib/aflibConverter.h	2014-01-30 14:55:50.000000000 +0100
@@ -110,7 +110,7 @@
    operator=(const aflibConverter& op);
 
    int
-   err_ret(char *s);
+   err_ret(const char *s);
 
    void
    deleteMemory();
