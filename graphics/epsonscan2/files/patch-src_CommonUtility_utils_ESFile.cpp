--- src/CommonUtility/utils/ESFile.cpp.orig	2024-09-12 07:10:38 UTC
+++ src/CommonUtility/utils/ESFile.cpp
@@ -45,6 +45,9 @@ CESFile* CESFile::CreateTempFileInstanceWithPrefix( ES
  }
 }
 CESFile* CESFile::CreateTempFileInstanceWithPrefix( ESString strFolder, ESString strPrefix, ES_OPEN_MODE eOpenMode ){
+ if (!ES_CMN_FUNCS::PATH::ES_IsWritableFolder(strFolder)) {
+  return FALSE;
+ }
  try {
   CESFile* pcFile = new CESFile();
   if( !pcFile->CreateTempFile(strFolder, strPrefix, eOpenMode) ){
