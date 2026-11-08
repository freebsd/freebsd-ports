--- src/EditDialog.cpp.orig	2026-08-31 03:45:50 UTC
+++ src/EditDialog.cpp
@@ -1,7 +1,6 @@
 #include "EditDialog.h"
 #include "ui_EditDialog.h"
 #include "Settings.h"
-#include "qhexedit.h"
 #include "docktextedit.h"
 #include "FileDialog.h"
 #include "Data.h"
@@ -22,6 +21,7 @@
 
 #include <Qsci/qsciscintilla.h>
 #include <json.hpp>
+#include <qhexedit2/qhexedit.h>
 
 using json = nlohmann::json;
 using ordered_json = nlohmann::ordered_json;
