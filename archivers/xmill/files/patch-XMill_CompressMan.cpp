--- XMill/CompressMan.cpp.orig	2016-07-26 12:48:05 UTC
+++ XMill/CompressMan.cpp
@@ -423,7 +423,7 @@ void BothCompressMan::DebugPrint()
    UserCompressorFactory *compressor=compressorlist;
    while(compressor!=NULL)
    {
-      printf("%lu =>",(unsigned int)compressor);
+      printf("%lu =>",(unsigned)(intptr_t)compressor);
       printf("%s\n",compressor->GetName());
       compressor=compressor->next;
    }
