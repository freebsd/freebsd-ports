--- widgets/awindowleveltoolbutton.cpp.orig	2010-07-27 14:58:36.000000000 +0000
+++ widgets/awindowleveltoolbutton.cpp	2010-07-27 14:58:44.000000000 +0000
@@ -2,6 +2,8 @@
 #include "aiconfactory.h"
 #include <iostream>
 
+#include <libintl.h>
+
 namespace Aeskulap {
 
 std::set<WindowLevelToolButton*> WindowLevelToolButton::m_widgetlist;
