--- src/libmongocrypt/src/mongocrypt-util.c.orig	2023-02-09 10:59:51 UTC
+++ src/libmongocrypt/src/mongocrypt-util.c
@@ -37,6 +37,8 @@
 
 #include <errno.h>
 
+#define FreeBSD 1
+
 #ifdef _WIN32
 #include <windows.h>
 #else
@@ -78,7 +80,7 @@ current_module_path ()
       }
       free (path);
    }
-#elif defined(_GNU_SOURCE) || defined(_DARWIN_C_SOURCE)
+#elif defined(FreeBSD) || defined(_GNU_SOURCE) || defined(_DARWIN_C_SOURCE)
    // Darwin/BSD/glibc define extensions for finding dynamic library info from
    // the address of a symbol.
    Dl_info info;
