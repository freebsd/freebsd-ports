--- src/version.cmake.orig	2023-08-20 13:24:21 UTC
+++ src/version.cmake
@@ -6,7 +6,7 @@ ELSE(GIT_EXECUTABLE)
 	)
 ELSE(GIT_EXECUTABLE)
 	MESSAGE(WARNING "Git binary not found. Build version will be set to NULL. Install Git package or use -DGIT_BINARY to set path to git binary.")
-	SET (VERSION "NULL")
+	SET (VERSION "%%DISTVERSION%%")
 ENDIF(GIT_EXECUTABLE)
 
 CONFIGURE_FILE(${SRC} ${DST} @ONLY)
