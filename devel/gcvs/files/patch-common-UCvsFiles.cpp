--- common/UCvsFiles.cpp.orig	2002-08-13 13:46:40.000000000 +0200
+++ common/UCvsFiles.cpp	2007-11-22 21:01:27.000000000 +0100
@@ -201,7 +201,7 @@
 
 #define NUM_COLUMNS	7
 
-static char *_gszColumnLabel[NUM_COLUMNS] =
+static const char *_gszColumnLabel[NUM_COLUMNS] =
 {
 	"Name", "Rev.", "Option", "Status",	"Tag", "Date", "Conflict"
 };
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
