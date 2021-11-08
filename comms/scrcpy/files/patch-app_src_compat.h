--- app/src/compat.h.orig	2021-11-07 06:03:53 UTC
+++ app/src/compat.h
@@ -1,8 +1,8 @@
 #ifndef COMPAT_H
 #define COMPAT_H
 
-#define _POSIX_C_SOURCE 200809L
-#define _XOPEN_SOURCE 700
+// #define _POSIX_C_SOURCE 200809L
+// #define _XOPEN_SOURCE 700
 #define _GNU_SOURCE
 #ifdef __APPLE__
 # define _DARWIN_C_SOURCE
