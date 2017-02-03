--- ui/zinf/src/ZinfTheme.cpp.orig	2003-09-16 17:36:22 UTC
+++ ui/zinf/src/ZinfTheme.cpp
@@ -1739,7 +1739,7 @@ void ZinfTheme::DropFiles(vector<string>
     countbefore = m_pContext->plm->CountItems();
 
     for(i = pFileList->begin(); i != pFileList->end(); i++){
-        char          *pExtension = NULL;
+        const char    *pExtension = NULL;
         vector<char*>  fileList;
         struct _stat   st;
 
