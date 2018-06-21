--- test/unity/unity.c.orig	2018-01-25 17:04:21 UTC
+++ test/unity/unity.c
@@ -19,9 +19,7 @@
 #ifdef __APPLE__
 struct _Unity Unity = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , { 0 } };        
 #else
-struct _Unity Unity = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 
-  .AbortFrame = { {.__jmpbuf = {0}, .__mask_was_saved = 0, .__saved_mask = {{0}} } }
-};
+struct _Unity Unity = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , { 0 } };        
 #endif
 
 const char* UnityStrNull     = "NULL";
