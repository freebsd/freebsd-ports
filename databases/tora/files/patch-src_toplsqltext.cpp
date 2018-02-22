Fix the build with clang 6.

toplsqltext.cpp:80:19: error: cannot initialize a member subobject of type 'const char *' with an rvalue of type 'bool'
    { NULL, NULL, false, false}
                  ^~~~~
--- src/toplsqltext.cpp.orig	2018-02-16 21:47:29 UTC
+++ src/toplsqltext.cpp
@@ -77,7 +77,7 @@ TypeMap[] = { { "FUNCTION", "Fc", ":/icons/function.pn
     { "LOOP", "Loop", NULL, false, false},
     { "WHILE", "Loop", NULL, false, false},
     { "FOR", "Loop", NULL, false, false},
-    { NULL, NULL, false, false}
+    { NULL, NULL, NULL, false, false}
 };
 
 
