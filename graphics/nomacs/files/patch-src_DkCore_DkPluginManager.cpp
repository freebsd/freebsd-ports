/wrkdirs/usr/ports/graphics/nomacs/work/nomacs-3.6.1/ImageLounge/src/DkCore/DkPluginManager.cpp:371:13: warning: '&&' within '||' [-Wlogical-op-parentheses]
        else if (p && p->interfaceType() == DkPluginInterface::interface_basic || p->interfaceType() == DkPluginInterface::interface_batch) {
                 ~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~
/wrkdirs/usr/ports/graphics/nomacs/work/nomacs-3.6.1/ImageLounge/src/DkCore/DkPluginManager.cpp:371:13: note: place parentheses around the '&&' expression to silence this warning
        else if (p && p->interfaceType() == DkPluginInterface::interface_basic || p->interfaceType() == DkPluginInterface::interface_batch) {
                   ^
                 (                                                            )

--- src/DkCore/DkPluginManager.cpp.orig	2019-07-07 07:04:23 UTC
+++ src/DkCore/DkPluginManager.cpp
@@ -368,7 +368,7 @@ void DkPluginContainer::run() {
 		connect(vPlugin->getViewPort(), SIGNAL(showToolbar(QToolBar*, bool)), vPlugin->getMainWindow(), SLOT(showToolbar(QToolBar*, bool)));
 		emit runPlugin(vPlugin, false);
 	}
-	else if (p && p->interfaceType() == DkPluginInterface::interface_basic || p->interfaceType() == DkPluginInterface::interface_batch) {
+	else if (p && (p->interfaceType() == DkPluginInterface::interface_basic || p->interfaceType() == DkPluginInterface::interface_batch)) {
 
 		QAction* a = qobject_cast<QAction*>(QObject::sender());
 
