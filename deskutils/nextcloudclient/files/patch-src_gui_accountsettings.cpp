--- src/gui/accountsettings.cpp.orig	2017-12-20 15:03:02 UTC
+++ src/gui/accountsettings.cpp
@@ -34,7 +34,8 @@
 #include "tooltipupdater.h"
 #include "filesystem.h"
 
-#include <math.h>
+#include <climits>
+#include <cmath>
 
 #include <QDesktopServices>
 #include <QDir>
