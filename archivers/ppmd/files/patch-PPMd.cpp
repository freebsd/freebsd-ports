--- PPMd.cpp.orig	2005-08-11 09:00:41 UTC
+++ PPMd.cpp
@@ -423,7 +423,7 @@ int main(int argc, char *argv[])
             default : printsilent(MTxt[5],argv[i]);   				return -1;
         }
 
-    printsilent("Fast PPMII compressor for textual data, variant %c, "__DATE__"\n",char(Variant));
+    printsilent("Fast PPMII compressor for textual data, variant %c, " __DATE__ "\n",char(Variant));
 
     FILE_LIST_NODE* pNode, * pFirstNode=NULL, ** ppNode=&pFirstNode;
     for (ENV_FILE_FINDER eff;i < argc;i++) {
