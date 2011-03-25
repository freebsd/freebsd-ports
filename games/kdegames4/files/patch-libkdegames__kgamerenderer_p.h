--- ./libkdegames/kgamerenderer_p.h.orig	2010-12-13 00:59:19.977474457 +0100
+++ ./libkdegames/kgamerenderer_p.h	2010-12-13 01:02:15.857318373 +0100
@@ -31,9 +31,10 @@
 namespace KGRInternal
 {
 	//Describes the state of a KGameRendererClient.
+	typedef QHash<QColor, QColor> qhash_qcolor_qcolor_t;
 	struct ClientSpec
 	{
-		inline ClientSpec(const QString& spriteKey = QString(), int frame = -1, const QSize& size = QSize(), const QHash<QColor, QColor>& customColors = QHash<QColor, QColor>());
+		inline ClientSpec(const QString& spriteKey = QString(), int frame = -1, const QSize& size = QSize(), const qhash_qcolor_qcolor_t& customColors = qhash_qcolor_qcolor_t());
 		QString spriteKey;
 		int frame;
 		QSize size;
