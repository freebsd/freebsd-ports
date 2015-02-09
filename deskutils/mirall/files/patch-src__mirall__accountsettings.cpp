--- src/mirall/accountsettings.cpp.orig
+++ src/mirall/accountsettings.cpp
@@ -29,7 +29,8 @@
 #include "selectivesyncdialog.h"
 #include "creds/abstractcredentials.h"
 
-#include <math.h>
+#include <climits>
+#include <cmath>
 
 #include <QDebug>
 #include <QDesktopServices>
