--- src/ice_string.c
+++ src/ice_string.c
@@ -334,8 +334,6 @@
 
 char *safe_strcat(char *dest, const char *src, unsigned int maxsize)
 {
-	int size = 0;
-
 	if (!dest || !src) return dest;
 
 	if (ice_strlen(dest) + ice_strlen(src)  + 1 >= maxsize) {
