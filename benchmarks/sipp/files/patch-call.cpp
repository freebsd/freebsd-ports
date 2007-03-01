$FreeBSD$

--- call.cpp.orig	Tue Jan 23 20:02:26 2007
+++ call.cpp	Fri Feb  9 01:49:46 2007
@@ -2216,13 +2216,17 @@
 
         auth_marker = src;
         auth_marker_len = strchr(src, ']') - src;
-        strcpy(my_auth_user, service);
-        strcpy(my_auth_pass, auth_password);
         /* Look for optional username and password parameters */
         /* add aka_OP, aka_AMF, aka_K */
         key = getKeywordParam(src, "username=", my_auth_user);
+        if (my_auth_user[0]==0){
+            strcpy(my_auth_user, service);
+        }
         memset(my_auth_pass,0,KEYWORD_SIZE);
         key = getKeywordParam(src, "password=", my_auth_pass);
+        if (my_auth_pass[0]==0){
+            strcpy(my_auth_pass, auth_password);
+        }
         memset(my_aka_OP,0,KEYWORD_SIZE);
         key = getKeywordParam(src, "aka_OP=", my_aka_OP);
         memset(my_aka_AMF,0,KEYWORD_SIZE);
