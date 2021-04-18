--- src/widgets/FileConfig.cpp.orig	2021-02-04 18:52:51 UTC
+++ src/widgets/FileConfig.cpp
@@ -10,6 +10,8 @@
 
 #include "../Audacity.h"
 
+#include <errno.h>
+
 #include <wx/defs.h>
 #include <wx/app.h>
 #include <wx/bmpbuttn.h>
