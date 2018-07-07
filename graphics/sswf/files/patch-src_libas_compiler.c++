--- src/libas/compiler.c++.orig	2018-07-07 18:08:29 UTC
+++ src/libas/compiler.c++
@@ -416,7 +416,7 @@ String IntCompiler::GetPackageFilename(const char *pac
 	int		cnt;
 
 	cnt = 0;
-	while(package_info != '\0') {
+	while(*package_info != '\0') {
 		package_info++;
 		if(package_info[-1] == ' ') {
 			cnt++;
