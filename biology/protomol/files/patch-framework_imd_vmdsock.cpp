--- framework/imd/vmdsock.cpp.orig	2005-05-07 14:40:25 UTC
+++ framework/imd/vmdsock.cpp
@@ -32,6 +32,7 @@ namespace ProtoMol {
 #include <stdio.h>
 #include <stdlib.h>
 #include <string>
+#include <cstring>
 using std::string;
 
 #if defined(WIN32)
