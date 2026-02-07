--- src/callback.c.orig	2022-07-19 17:26:18 UTC
+++ src/callback.c
@@ -82,7 +82,7 @@ static int generate_native_callback(WORD_LIST *list)
     ffi_type *callbacktype;
     char **proto;
     char *resultname = "DLRETVAL";
-    char opt;
+    int opt;
     reset_internal_getopt();
 
     while ((opt = internal_getopt(list, "d:n:")) != -1) {
