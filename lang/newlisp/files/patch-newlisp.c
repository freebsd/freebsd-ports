
$FreeBSD$

--- newlisp.c.orig
+++ newlisp.c
@@ -463,16 +463,16 @@
     else if(getenv("DOCUMENT_ROOT"))
         strncpy(initFile, getenv("DOCUMENT_ROOT"), MAX_LINE - 16);
 
-    strncat(initFile, "/.", 2);
-    strncat(initFile, INIT_FILE, 9);
+    strlcat(initFile, "/.", sizeof(initFile));
+    strlcat(initFile, INIT_FILE, sizeof(initFile));
     if(loadFile(initFile, 0, 0, mainContext) == NULL)
         {
         envPtr = getenv("NEWLISPDIR");
         if(envPtr)
             {
-            strncpy(initFile, envPtr, MAX_LINE - 16);
-            strncat(initFile, "/", 1);
-            strncat(initFile, INIT_FILE, 9);
+            strlcpy(initFile, envPtr, sizeof(initFile));
+            strlcat(initFile, "/", sizeof(initFile));
+            strlcat(initFile, INIT_FILE, sizeof(initFile));
             loadFile(initFile, 0, 0, mainContext);      
             }
         }
