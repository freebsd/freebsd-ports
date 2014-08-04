--- src/StelMainGraphicsView.cpp.orig	2013-09-07 23:50:48.000000000 +0800
+++ src/StelMainGraphicsView.cpp	2013-10-19 19:49:37.000000000 +0800
@@ -43,6 +43,8 @@
 #include <QTimer>
 #include <QDir>
 
+#include <locale>
+
 #ifndef DISABLE_SCRIPTING
  #include "StelScriptMgr.hpp"
  #include "StelMainScriptAPIProxy.hpp"
