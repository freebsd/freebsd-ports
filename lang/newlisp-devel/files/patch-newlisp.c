
$FreeBSD$

--- newlisp.c.orig
+++ newlisp.c
@@ -515,16 +515,16 @@
     else if(getenv("DOCUMENT_ROOT"))
         strncpy(initFile, getenv("DOCUMENT_ROOT"), PATH_MAX - 16);
 
-    strncat(initFile, "/.", 2);
-    strncat(initFile, INIT_FILE, 8);
+    strlcat(initFile, "/.", sizeof(initFile));
+    strlcat(initFile, INIT_FILE, sizeof(initFile));
     if(loadFile(initFile, 0, 0, mainContext) == NULL)
         {
         envPtr = getenv("NEWLISPDIR");
         if(envPtr)
             {
-            strncpy(initFile, envPtr, PATH_MAX - 16);
-            strncat(initFile, "/", 1);
-            strncat(initFile, INIT_FILE, 8);
+            strlcpy(initFile, envPtr, sizeof(initFile));
+            strlcat(initFile, "/", sizeof(initFile));
+            strlcat(initFile, INIT_FILE, sizeof(initFile));
             loadFile(initFile, 0, 0, mainContext);      
             }
         }
