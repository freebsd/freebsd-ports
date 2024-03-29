--- src/default.c.orig	2020-01-03 07:11:27 UTC
+++ src/default.c
@@ -530,7 +530,7 @@ static const char *default_variables[] =
     "OBJC", "gcc",
 #else
     "CC", "cc",
-    "CXX", "g++",
+    "CXX", "c++",
     "OBJC", "cc",
 #endif
 
