--- common/UCvsFiles.cpp.orig	Tue Aug 13 13:46:40 2002
+++ common/UCvsFiles.cpp	Sun Aug 24 13:47:21 2003
@@ -1214,7 +1214,7 @@
 {
 	UStr uppath, filename;
 	SplitPath(m_path, uppath, filename);
-	ResetView(uppath, true);
+	ResetView( (const char *)uppath, true);
 	return 0;
 }
 
@@ -1895,7 +1895,7 @@
 	fullpath << (*data)[EntnodeData::kName];
 	if(data->GetType() == ENT_SUBDIR)
 	{
-		ResetView(fullpath, true);
+		ResetView( (const char *)fullpath, true);
 	}
 	else
 	{
