--- src/serialization/base64.cpp.orig	2025-02-17 21:50:08 UTC
+++ src/serialization/base64.cpp
@@ -15,6 +15,7 @@
 
 #include "serialization/base64.hpp"
 
+#include <cstdint>
 #include <string>
 
 namespace {
