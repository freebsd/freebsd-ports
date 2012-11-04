
$FreeBSD$

--- newlisp.c.orig
+++ newlisp.c
@@ -470,16 +470,16 @@
         strncpy(initFile, getenv("DOCUMENT_ROOT"), MAX_LINE - 16);
 
     /* for non BSDs strlcat and strlcpy are redefined as strncat and strncpy */
-    strlcat(initFile, "/.", 3);
-    strlcat(initFile, INIT_FILE, 9);
+    strlcat(initFile, "/.", sizeof(initFile));
+    strlcat(initFile, INIT_FILE, sizeof(initFile));
     if(loadFile(initFile, 0, 0, mainContext) == NULL)
         {
         envPtr = getenv("NEWLISPDIR");
         if(envPtr)
             {
-            strlcpy(initFile, envPtr, MAX_LINE - 16);
-            strlcat(initFile, "/", 2);
-            strlcat(initFile, INIT_FILE, 9);
+            strlcpy(initFile, envPtr, sizeof(initFile));
+            strlcat(initFile, "/", sizeof(initFile));
+            strlcat(initFile, INIT_FILE, sizeof(initFile));
             loadFile(initFile, 0, 0, mainContext);      
             }
         }
