Fix build with Qt6/C++17. Follow KDE upstream trend and replace Q_DECL_UNUSED
with the C++17 [[maybe_unused]] attribute. Heaptrack still supports Qt5, so
keeping this local.

/usr/ports/devel/heaptrack/work/heaptrack-1.5.0/src/analyze/gui/gui.cpp:26:6:
error: 'maybe_unused' attribute cannot be applied to types
   26 | void Q_DECL_UNUSED initRCCIconTheme()
      |      ^
/usr/local/include/qt6/QtCore/qcompilerdetection.h:978:27: note: expanded from macro 'Q_DECL_UNUSED'
  978 | #  define Q_DECL_UNUSED [[maybe_unused]]
      |                           ^
1 error generated.

--- src/analyze/gui/gui.cpp.orig	2023-09-29 17:02:09 UTC
+++ src/analyze/gui/gui.cpp
@@ -23,7 +23,7 @@
 #include <QResource>
 
 // FIXME: patch KIconTheme so that this isn't needed here
-void Q_DECL_UNUSED initRCCIconTheme()
+[[maybe_unused]] void initRCCIconTheme()
 {
     const QString iconThemeRcc = qApp->applicationDirPath() + QStringLiteral("/../share/icons/breeze/breeze-icons.rcc");
     if (!QFile::exists(iconThemeRcc)) {
