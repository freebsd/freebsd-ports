--- ym2wav.cpp.orig	2016-07-26 16:04:42 UTC
+++ ym2wav.cpp
@@ -71,7 +71,7 @@ typedef struct
 
 int main(int argc, char* argv[])
 {
-	char *platform;
+	const char *platform;
 
 	if (PLATFORM)
 		platform = "64bit";
