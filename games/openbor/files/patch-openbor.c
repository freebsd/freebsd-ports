Fix an infinite loop in lcmScriptDeleteMain()

--- openbor.c.orig	2024-01-02 00:04:19 UTC
+++ openbor.c
@@ -12499,7 +12499,8 @@ size_t lcmScriptDeleteMain(char **buf)
 
 size_t lcmScriptDeleteMain(char **buf)
 {
-    size_t len = 0, i = 0;
+    size_t len = 0;
+    long i = 0;
     ptrdiff_t pos = 0;
     char *newbuf = NULL;
 
