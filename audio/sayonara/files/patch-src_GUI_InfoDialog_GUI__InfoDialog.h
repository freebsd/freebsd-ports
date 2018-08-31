Fix build with Qt 5.11

--- src/GUI/InfoDialog/GUI_InfoDialog.h.orig	2018-08-31 09:31:17 UTC
+++ src/GUI/InfoDialog/GUI_InfoDialog.h
@@ -29,6 +29,8 @@
 #include "Utils/MetaData/MetaDataFwd.h"
 #include "Utils/Pimpl.h"
 
+#include <QTabBar>
+
 class GUI_TagEdit;
 class GUI_Lyrics;
 class InfoDialogContainer;
