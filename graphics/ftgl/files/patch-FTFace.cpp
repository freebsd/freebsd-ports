--- src/FTFace.cpp.orig	Fri Jan 16 13:23:11 2004
+++ src/FTFace.cpp	Fri Jan 16 13:23:23 2004
@@ -62,7 +62,7 @@
 {
     FT_Open_Args open;
 
-    open.flags = (FT_Open_Flags)1; // FT_OPEN_MEMORY;
+    open.flags = /*(FT_Open_Flags)*/1; // FT_OPEN_MEMORY;
     open.memory_base = (FT_Byte *)pBufferBytes;
     open.memory_size = bufferSizeInBytes;
 
