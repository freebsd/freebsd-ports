--- hts_utils.h.orig	2020-11-08 22:09:58 UTC
+++ hts_utils.h
@@ -47,7 +47,7 @@ typedef struct {
 
 KHASH_MAP_INIT_STR(s, faidx1_t)
 
-struct __faidx_t {
+struct faidx_t {
     BGZF *bgzf;
     int n, m;
     char **name;
