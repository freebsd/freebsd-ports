--- src/libboardgame_sgf/MissingProperty.cpp.orig	2017-06-06 11:23:03 UTC
+++ src/libboardgame_sgf/MissingProperty.cpp
@@ -10,17 +10,19 @@
 
 #include "MissingProperty.h"
 
+#include <string>
+
 namespace libboardgame_sgf {
 
 //-----------------------------------------------------------------------------
 
 MissingProperty::MissingProperty(const string& message)
-    : InvalidTree("Missing SGF property: " + message)
+    : InvalidTree(string{"Missing SGF property: "} + message)
 {
 }
 
 MissingProperty::MissingProperty(const string& id, const string& message)
-    : InvalidTree("Missing SGF property '" + id + ": " + message)
+    : InvalidTree(string{"Missing SGF property '"} + id + ": " + message)
 {
 }
 
