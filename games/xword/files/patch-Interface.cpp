--- src/Interface.cpp.orig	Sat Nov  2 02:54:11 2002
+++ src/Interface.cpp	Sat Nov  2 02:54:33 2002
@@ -34,6 +34,7 @@
 #include <gtk--/toolbar.h>
 #include <gtk--/window.h>
 #include <stdexcept>
+#include <algorithm>
 
 #include "Error.h"
 #include "Filename.h"
@@ -42,6 +43,8 @@
 #include "String.h"
 
 #include "Namespace.h"
+
+using namespace std;
 
 NAMESPACE_OPEN
 
