--- src/bitcask.c.orig	2013-07-17 08:09:12 UTC
+++ src/bitcask.c
@@ -99,12 +99,12 @@ Bitcask* bc_open2(Mgr *mgr, int depth, i
     return bc;
 }
 
-inline bool file_exists(const char *path) {
+static inline bool file_exists(const char *path) {
     struct stat st;
     return stat(path, &st) == 0;
 }
 
-inline char *gen_path(char *dst, const char *base, const char *fmt, int i)
+static inline char *gen_path(char *dst, const char *base, const char *fmt, int i)
 {
     static char path[256];
     char name[16];
@@ -114,7 +114,7 @@ inline char *gen_path(char *dst, const c
     return dst;
 }
 
-inline char *new_path(char *dst, Mgr *mgr, const char *fmt, int i)
+static inline char *new_path(char *dst, Mgr *mgr, const char *fmt, int i)
 {
     char *path = gen_path(dst, mgr_base(mgr), fmt, i);
     if (!file_exists(dst)) {
