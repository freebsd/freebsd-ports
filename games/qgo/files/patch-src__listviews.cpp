--- src/listviews.cpp.orig
+++ src/listviews.cpp
@@ -342,7 +342,7 @@
 {
 	for(int i = 0; i < items.count(); i++)
 	{
-		GamesListItem * const item = static_cast<const GamesListItem *>(items[i]);
+		const GamesListItem * item = static_cast<const GamesListItem *>(items[i]);
 		if(item->getListing() == l)
 		{
 			/* Really this is supposed to be not QModelIndex() but the
