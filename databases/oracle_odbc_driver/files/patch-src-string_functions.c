--- src/string_functions.c.orig	Thu Jun  9 18:18:53 2005
+++ src/string_functions.c	Thu Jun  9 18:18:36 2005
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
 
