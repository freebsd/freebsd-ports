--- src/appwin.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/appwin.cpp
@@ -20,6 +20,7 @@
 #include <fx.h>
 #include <fxkeys.h>
 
+#include "compat.h"
 #include "scidoc.h"
 #include "doctabs.h"
 #include "search.h"
@@ -36,7 +37,6 @@
 #include "statusbar.h"
 #include "scidoc_util.h"
 #include "foreachtab.h"
-#include "compat.h"
 
 #include "intl.h"
 #include "appwin.h"
