--- src/gui/accountsettings.cpp.orig	2015-03-16 14:28:58 UTC
+++ src/gui/accountsettings.cpp
@@ -30,7 +30,8 @@
 #include "selectivesyncdialog.h"
 #include "creds/abstractcredentials.h"
 
-#include <math.h>
+#include <climits>
+#include <cmath>
 
 #include <QDebug>
 #include <QDesktopServices>
