--- src/string_functions.c.orig	2003-02-10 21:43:54.000000000 +0600
+++ src/string_functions.c	2009-03-03 01:30:14.000000000 +0600
@@ -81,19 +81,25 @@
 {
     char *local_str=NULL;
     int i;
-    if(str_len==SQL_NTS){ 
-        if(str&&str[0])
-		for(i=0; i<strlen(str); i++)
-			str[i]=toupper(str[i]);
-        return((char*)str);
-   }
+
+    if(str_len==SQL_NTS)
+    {
+        if(!str || !str[0])
+            return((char*)str);
+
+        /*
+         * always copy to malloc'ed string because str
+         * may point to read-only memory
+         */
+        str_len = strlen(str);
+    }
     if(str_len>=0)
     {
         local_str=ORAMALLOC(str_len+1);
         memcpy(local_str,str,str_len);
         local_str[str_len] = '\0';
     }
-    for(i=0; i<str_len; i++)local_str[i]=toupper(local_str[i]);
+    for(i=0; i<str_len; i++)local_str[i]=toupper((unsigned char) local_str[i]);
     return(local_str);
 }
 
@@ -149,7 +155,7 @@
  * 1) Will alway NULL terminate
  * 2) returns true if all OK, false if a bounds checking or other error occurs.
  */ 
-int ood_bounded_strcpy(char *dest,char* src, int limit)
+int ood_bounded_strcpy(char *dest, const char* src, int limit)
 {
     int i;
 
