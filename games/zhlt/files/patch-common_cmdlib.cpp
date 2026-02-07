--- common/cmdlib.cpp.orig	2016-03-30 06:24:01 UTC
+++ common/cmdlib.cpp
@@ -13,6 +13,9 @@
 #ifdef HAVE_SYS_STAT_H
 #include <sys/stat.h>
 #endif
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #endif
@@ -21,6 +24,8 @@
 #endif
 #endif
 
+#include <algorithm>
+
 #define PATHSEPARATOR(c) ((c) == '\\' || (c) == '/')
 
 /*
@@ -128,7 +133,7 @@ inline void getFilePositions(char* path,
 	else
 	{ *extension_position = ptr - path; }
 
-	ptr = max(strrchr(path,'/'),strrchr(path,'\\'));
+	ptr = std::max(strrchr(path,'/'),strrchr(path,'\\'));
 	if(ptr == 0)
 	{ *directory_position = -1; }
 	else
