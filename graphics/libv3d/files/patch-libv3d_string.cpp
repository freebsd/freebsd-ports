--- libv3d/string.cpp.orig	2007-11-16 12:31:03.000000000 +0100
+++ libv3d/string.cpp	2007-11-16 12:39:14.000000000 +0100
@@ -1012,20 +1012,20 @@
 
         /* Is string empty? */
         if(string == NULL)
-            return("");
+            return((char *)"");
 	if((string[0] == '\0') ||
            (string[0] == '\r') ||
            (string[0] == '\n')
         )
-            return("");
+            return((char *)"");
 
         /* Is string a comment? */
         if(StringIsComment(string, UNIXCFG_COMMENT_CHAR))
-            return("");
+            return((char *)"");
 
         /* Does string have a delimiter? */
         if(strchr(string, CFG_PARAMETER_DELIMITER) == NULL)
-            return("");
+            return((char *)"");
 
 
         /* Begin fetching value from string. */
@@ -1295,7 +1295,7 @@
 	static char arg[CS_DATA_MAX_LEN];
 
         if(str == NULL)
-            return("");
+            return((char *)"");
 
         strncpy(arg, str, CS_DATA_MAX_LEN);
         arg[CS_DATA_MAX_LEN - 1] = '\0';
@@ -1309,7 +1309,7 @@
             return(strptr);
         }
 
-        return("");
+        return((char *)"");
 }
 
 
@@ -1337,15 +1337,15 @@
 
 
         if(format == NULL)
-            return("");
+            return((char *)"");
         if((*format) == '\0')
-            return("");
+            return((char *)"");
 
 	/* Get current time. */
         time(&current);
         tm_ptr = localtime(&current);
 	if(tm_ptr == NULL)
-	    return("");
+	    return((char *)"");
 
         /* Format time string. */
 	len = strftime(
@@ -1377,13 +1377,13 @@
 
 
         if(format == NULL)
-            return("");
+            return((char *)"");
         if((*format) == '\0')
-            return("");
+            return((char *)"");
 
         tm_ptr = localtime(&seconds);
 	if(tm_ptr == NULL)
-	    return("");
+	    return((char *)"");
 
         /* Format time string. */
         len = strftime(
