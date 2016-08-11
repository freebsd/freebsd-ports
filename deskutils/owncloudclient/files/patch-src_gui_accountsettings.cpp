--- src/gui/accountsettings.cpp.orig	2016-05-12 07:59:12 UTC
+++ src/gui/accountsettings.cpp
@@ -31,7 +31,8 @@
 #include "creds/abstractcredentials.h"
 #include "tooltipupdater.h"
 
-#include <math.h>
+#include <climits>
+#include <cmath>
 
 #include <QDebug>
 #include <QDesktopServices>
