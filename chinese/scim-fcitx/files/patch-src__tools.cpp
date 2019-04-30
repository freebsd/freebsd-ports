--- src/tools.cpp.orig	2005-05-20 14:41:12 UTC
+++ src/tools.cpp
@@ -14,6 +14,7 @@ using namespace scim;
 #include <sys/stat.h>
 #include <limits.h>
 #include <string.h>
+#include <unistd.h> // for access()
 
 #include "version.h"
 #include "PYFA.h"
