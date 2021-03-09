--- src/VBox/Frontends/VirtualBox/src/widgets/UIMiniToolBar.cpp.orig	2020-05-18 15:15:26 UTC
+++ src/VBox/Frontends/VirtualBox/src/widgets/UIMiniToolBar.cpp
@@ -28,6 +28,7 @@
 # include <QToolButton>
 # include <QStateMachine>
 # include <QPainter>
+# include <QPainterPath>
 # include <QWindow>
 # ifdef VBOX_WS_X11
 #  include <QWindowStateChangeEvent>
