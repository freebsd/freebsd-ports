--- HelperFunctions.c.orig	2020-06-04 23:58:40 UTC
+++ HelperFunctions.c
@@ -845,7 +845,7 @@ int strcmp_number(char * s1, char * s2)
 
 int mac_str(char * str_buff)
 {
-#if defined(FREEBSD) || defined(__MINGW32__)
+#if defined(__FreeBSD__) || defined(__MINGW32__)
 	return 1;
 #else
 #ifdef MACOS
@@ -2703,7 +2703,7 @@ void main(){
 
 int get_free_total_mem(size_t * total, size_t * free_mem){
 
-#ifdef FREEBSD
+#ifdef __FreeBSD__
     return -1;
 #endif
 
