--- ./libkdegames/kgamerenderer.h.orig	2010-12-13 00:33:42.457494012 +0100
+++ ./libkdegames/kgamerenderer.h	2010-12-13 00:41:21.837310103 +0100
@@ -208,7 +208,8 @@
 		///@note  For non-animated frames, set @a frame to -1 or omit it.
 		///@note  Custom colors increase the rendering time considerably, so use
 		///       this feature only if you really need its flexibility.
-		QPixmap spritePixmap(const QString& key, const QSize& size, int frame = -1, const QHash<QColor, QColor>& customColors = QHash<QColor, QColor>()) const;
+		typedef QHash<QColor, QColor> qhash_qcolor_qcolor_t;
+		QPixmap spritePixmap(const QString& key, const QSize& size, int frame = -1, const qhash_qcolor_qcolor_t& customColors = qhash_qcolor_qcolor_t()) const;
 	public Q_SLOTS:
 		///Load the given theme and update the pixmaps of all associated
 		///KGameRendererClient instances.
