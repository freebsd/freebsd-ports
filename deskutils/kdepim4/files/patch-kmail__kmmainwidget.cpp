--- kmail/kmmainwidget.cpp
+++ kmail/kmmainwidget.cpp
@@ -165,6 +165,9 @@ using KMail::TemplateParser;
 
 #include <errno.h> // ugh
 
+#include <akonadi/control.h>
+#include <akonadi/servermanager.h>
+
 #include "kmmainwidget.moc"
 
 K_GLOBAL_STATIC( KMMainWidget::PtrList, theMainWidgetList )
@@ -186,6 +189,10 @@ KMMainWidget::KMMainWidget( QWidget *parent, KXMLGUIClient *aGUIClient,
     mVacationIndicatorActive( false ),
     mGoToFirstUnreadMessageInSelectedFolder( false )
 {
+#if KDE_IS_VERSION(4,6,0)
+  Akonadi::Control::widgetNeedsAkonadi(this);
+  Akonadi::ServerManager::start();
+#endif
   // must be the first line of the constructor:
   mStartupDone = false;
   mWasEverShown = false;
