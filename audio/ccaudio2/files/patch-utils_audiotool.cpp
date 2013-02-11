--- utils/audiotool.cpp.orig	2011-03-21 08:16:40.000000000 +0100
+++ utils/audiotool.cpp	2013-02-11 15:13:11.000000000 +0100
@@ -20,6 +20,13 @@
 #include <config.h>
 #ifdef  HAVE_ENDIAN_H
 #include <endian.h>
+#else
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
+#endif
 #endif
 
 #if !defined(__BIG_ENDIAN)
@@ -401,12 +408,12 @@
         framing = 20;
 
     while(*argv) {
-        if(!fsys::isfile(*argv)) {
+        if(!fsys::is_file(*argv)) {
             printf("%s: %s\n",
                 fname(*(argv++)), _TEXT("invalid"));
             continue;
         }
-        if(fsys::access(*argv, R_OK)) {
+        if(!fsys::is_readable(*argv)) {
             printf("%s: %s\n",
                 fname(*(argv++)), _TEXT("inaccessable"));
             continue;
@@ -530,12 +537,12 @@
     }
 
     while(*argv) {
-        if(!fsys::isfile(*argv)) {
+        if(!fsys::is_file(*argv)) {
             printf("audiotool: %s: %s\n",
                 fname(*(argv++)), _TEXT("invalid"));
             continue;
         }
-        if(fsys::access(*argv, R_OK)) {
+        if(!fsys::is_readable(*argv)) {
             printf("audiotool: %s: %s\n",
                 fname(*(argv++)), _TEXT("inaccessable"));
             continue;
@@ -682,12 +689,12 @@
         framing = 20;
 
     while(*argv) {
-        if(!fsys::isfile(*argv)) {
+        if(!fsys::is_file(*argv)) {
             printf("%s: %s\n",
                 *(argv++), _TEXT("invalid"));
             continue;
         }
-        if(fsys::access(*argv, R_OK)) {
+        if(!fsys::is_readable(*argv)) {
             printf("%s: %s\n",
                 *(argv++), _TEXT("inaccessable"));
             continue;
@@ -881,12 +888,12 @@
         framing = 20;
 
     while(*argv) {
-        if(!fsys::isfile(*argv)) {
+        if(!fsys::is_file(*argv)) {
             printf("%s: %s\n",
                 *(argv++), _TEXT("invalid"));
             continue;
         }
-        if(fsys::access(*argv, R_OK)) {
+        if(!fsys::is_readable(*argv)) {
             printf("%s: %s\n",
                 *(argv++), _TEXT("inaccessable"));
             continue;
