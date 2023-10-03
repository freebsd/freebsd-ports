--- src/gui/kernel/qx11embed_x11.cpp.orig	2023-10-03 21:02:05 UTC
+++ src/gui/kernel/qx11embed_x11.cpp
@@ -483,7 +483,7 @@ QX11EmbedWidget::QX11EmbedWidget(QWidget *parent)
                     | ExposureMask | StructureNotifyMask
                     | SubstructureNotifyMask | PropertyChangeMask);
 
-    long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
+    long data[] = {static_cast<long>(XEMBED_VERSION), XEMBED_MAPPED};
     XChangeProperty(x11Info().display(), internalWinId(), ATOM(_XEMBED_INFO),
                     ATOM(_XEMBED_INFO), 32, PropModeReplace,
                     (unsigned char*) data, 2);
@@ -1578,7 +1578,7 @@ void QX11EmbedContainer::showEvent(QShowEvent *)
 {
     Q_D(QX11EmbedContainer);
     if (d->client) {
-        long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
+        long data[] = {static_cast<long>(XEMBED_VERSION), XEMBED_MAPPED};
 	XChangeProperty(x11Info().display(), d->client, ATOM(_XEMBED_INFO), ATOM(_XEMBED_INFO), 32,
 			PropModeReplace, (unsigned char *) data, 2);
     }
@@ -1594,7 +1594,7 @@ void QX11EmbedContainer::hideEvent(QHideEvent *)
 {
     Q_D(QX11EmbedContainer);
     if (d->client) {
-        long data[] = {XEMBED_VERSION, XEMBED_MAPPED};
+        long data[] = {static_cast<long>(XEMBED_VERSION), XEMBED_MAPPED};
 	XChangeProperty(x11Info().display(), d->client, ATOM(_XEMBED_INFO), ATOM(_XEMBED_INFO), 32,
 			PropModeReplace, (unsigned char *) data, 2);
     }
