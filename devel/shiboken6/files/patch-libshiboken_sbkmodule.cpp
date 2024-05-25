/wrkdirs/usr/ports/devel/shiboken6/work-py39/pyside-setup-everywhere-src-6.7.1/sources/shiboken6/libshiboken/sbkmodule.cpp:459:15:
error: no member named 'Conversions' in namespace 'Shiboken'
    Shiboken::Conversions::clearNegativeLazyCache();

Regressed by: https://code.qt.io/cgit/pyside/pyside-setup.git/commit/?h=6.7.1&id=d332a3e3a7a35f8e5825fc10fb649f085243f323

--- libshiboken/sbkmodule.cpp.orig	2024-05-17 17:05:40 UTC
+++ libshiboken/sbkmodule.cpp
@@ -7,6 +7,7 @@
 #include "bindingmanager.h"
 #include "sbkstring.h"
 #include "sbkcppstring.h"
+#include "sbkconverter_p.h"
 
 #include <unordered_map>
 #include <unordered_set>
