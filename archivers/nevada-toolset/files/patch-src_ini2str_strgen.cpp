--- src/ini2str/strgen.cpp.orig	2020-08-15 22:06:32 UTC
+++ src/ini2str/strgen.cpp
@@ -15,6 +15,7 @@
 #include "always.h"
 #include "ini2str.h"
 #include "win32compat.h"
+#include <cstdio>
 #include <cstring>
 
 using std::strcmp;
