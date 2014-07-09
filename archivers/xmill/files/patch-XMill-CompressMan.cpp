--- XMill/CompressMan.cpp.orig	2009-03-13 19:11:05.000000000 +0100
+++ XMill/CompressMan.cpp	2009-03-13 19:11:08.000000000 +0100
@@ -423,7 +423,7 @@
    UserCompressorFactory *compressor=compressorlist;
    while(compressor!=NULL)
    {
-      printf("%lu =>",(unsigned int)compressor);
+      printf("%lu =>",(unsigned)(intptr_t)compressor);
       printf("%s\n",compressor->GetName());
       compressor=compressor->next;
    }
