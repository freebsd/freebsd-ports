--- tests/server/getpart.c.old	Tue Sep  2 14:05:23 2003
+++ tests/server/getpart.c	Tue Sep  2 14:07:16 2003
@@ -20,7 +20,7 @@
 {
   int len = strlen(buffer);
 
-  if((len + *stringlen) >= *stralloc) {
+  while((len + *stringlen) >= *stralloc) {
     char *newptr= realloc(string, *stralloc*2);
     if(newptr) {
       string = newptr;
@@ -56,6 +56,7 @@
   } state = STATE_OUTSIDE;
 
   string = (char *)malloc(stralloc);
+  string[0] = '\0';
   
   while(fgets(buffer, sizeof(buffer), stream)) {
 
