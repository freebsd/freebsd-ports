--- sources/editor/elementscene.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/editor/elementscene.cpp
@@ -748,7 +748,7 @@ void ElementScene::removeItems(QVector<QGraphicsItem *
  */
 void ElementScene::removeItems(QVector<QGraphicsItem *> items)
 {
-	const int previous_selected_count{selectedItems().size()};
+	const int previous_selected_count{static_cast<int>(selectedItems().size())};
 
 		//block signal to avoid multiple emit of selection changed,
 		//we emit this signal only once at the end of this function.
