--- aflib/aflibConverter.h.orig	2007-01-16 19:26:39 UTC
+++ aflib/aflibConverter.h
@@ -110,7 +110,7 @@ private:
    operator=(const aflibConverter& op);
 
    int
-   err_ret(char *s);
+   err_ret(const char *s);
 
    void
    deleteMemory();
