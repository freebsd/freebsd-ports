--- src/VBox/Frontends/VirtualBox/src/widgets/UIMiniToolBar.cpp.orig	2017-04-18 09:53:23 UTC
+++ src/VBox/Frontends/VirtualBox/src/widgets/UIMiniToolBar.cpp
@@ -29,7 +29,9 @@
 # include <QToolButton>
 # include <QStateMachine>
 # include <QPainter>
-# include <QWindow>
+# if QT_VERSION >= 0x050000
+#  include <QWindow>
+# endif
 # ifdef VBOX_WS_X11
 #  include <QWindowStateChangeEvent>
 # endif
@@ -616,8 +618,10 @@ void UIMiniToolBar::sltShow()
 {
     LogRel2(("GUI: UIMiniToolBar::sltShow\n"));
 
+#if QT_VERSION >= 0x050000
     /* Update transience: */
     sltAdjustTransience();
+#endif
 
 #if defined(VBOX_WS_MAC)
 
@@ -806,6 +810,7 @@ void UIMiniToolBar::sltAdjust()
 #endif
 }
 
+#if QT_VERSION >= 0x050000
 void UIMiniToolBar::sltAdjustTransience()
 {
     // WORKAROUND:
@@ -817,6 +822,7 @@ void UIMiniToolBar::sltAdjustTransience(
     /* Add the transience dependency: */
     windowHandle()->setTransientParent(m_pParent->windowHandle());
 }
+#endif
 
 void UIMiniToolBar::prepare()
 {
