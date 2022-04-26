--- src/CommonUtility/utils/ESFile.cpp.orig	2021-11-25 00:56:55 UTC
+++ src/CommonUtility/utils/ESFile.cpp
@@ -48,6 +48,9 @@ CESFile* CESFile::CreateFileInstanceWithPath(ESString 
  }
 }
 CESFile* CESFile::CreateTempFileInstanceWithPrefix( ESString strFolder, ESString strPrefix, ES_OPEN_MODE eOpenMode ){
+ if (!ES_CMN_FUNCS::PATH::ES_IsWritableFolder(strFolder)) {
+  return FALSE;
+ }
  try {
   CESFile* pcFile = new CESFile();
   if( !pcFile->CreateTempFile(strFolder, strPrefix, eOpenMode) ){
