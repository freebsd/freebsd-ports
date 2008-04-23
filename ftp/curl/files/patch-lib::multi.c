diff -urN -urN -x .svn ../../vendor/curl/lib/multi.c ./lib/multi.c
--- ../../vendor/curl/lib/multi.c	2008-03-24 00:40:11.000000000 +0200
+++ ./lib/multi.c	2008-03-29 16:14:27.000000000 +0200
@@ -324,7 +324,7 @@
 {
   (void) k1_len; (void) k2_len;
 
-  return ((*((int* ) k1)) == (*((int* ) k2))) ? 1 : 0;
+  return (*((int* ) k1)) == (*((int* ) k2));
 }
 
 static size_t hash_fd(void* key, size_t key_length, size_t slots_num)
