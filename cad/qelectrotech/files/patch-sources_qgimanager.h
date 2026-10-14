--- sources/qgimanager.h.orig	2026-01-28 12:19:13 UTC
+++ sources/qgimanager.h
@@ -45,10 +45,6 @@ class QGIManager {
 	public:
 	void manage(QGraphicsItem *);
 	void release(QGraphicsItem *);
-	QT_DEPRECATED_X("Use QGIManager::manage(const QVector<QGraphicsItem *> &) instead")
-		void manage(const QList<QGraphicsItem *> &);
-	QT_DEPRECATED_X("Use QGIManager::release(const QVector<QGraphicsItem *> &) instead")
-		void release(const QList<QGraphicsItem *> &);
 	void manage(const QVector<QGraphicsItem *> &items);
 	void release(const QVector<QGraphicsItem *> &items);
 	void setDestroyQGIOnDelete(bool);
