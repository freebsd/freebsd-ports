--- ThumbnailSequence.cpp.orig	2012-02-27 20:21:08 UTC
+++ ThumbnailSequence.cpp
@@ -489,7 +489,7 @@ ThumbnailSequence::Impl::Impl(
 	m_pSelectionLeader(0)
 {
 	m_graphicsScene.setContextMenuEventCallback(
-		bind(&Impl::sceneContextMenuEvent, this, _1)
+		boost::lambda::bind(&Impl::sceneContextMenuEvent, this, boost::lambda::_1)
 	);
 }
 
@@ -603,7 +603,7 @@ ThumbnailSequence::Impl::invalidateThumb
 {
 	ItemsById::iterator const id_it(m_itemsById.find(page_info.id()));
 	if (id_it != m_itemsById.end()) {
-		m_itemsById.modify(id_it, bind(&Item::pageInfo, _1) = page_info);
+		m_itemsById.modify(id_it, boost::lambda::bind(&Item::pageInfo, boost::lambda::_1) = page_info);
 		invalidateThumbnailImpl(id_it);
 	}
 }
@@ -723,10 +723,10 @@ ThumbnailSequence::Impl::invalidateAllTh
 	// Sort pages in m_itemsInOrder using m_ptrOrderProvider.
 	if (m_ptrOrderProvider.get()) {
 		m_itemsInOrder.sort(
-			bind(
+			boost::lambda::bind(
 				&PageOrderProvider::precedes, m_ptrOrderProvider.get(),
-				bind(&Item::pageId, _1), bind(&Item::incompleteThumbnail, _1),
-				bind(&Item::pageId, _2), bind(&Item::incompleteThumbnail, _2) 
+				boost::lambda::bind(&Item::pageId, boost::lambda::_1), bind(&Item::incompleteThumbnail, boost::lambda::_1),
+				boost::lambda::bind(&Item::pageId, boost::lambda::_2), bind(&Item::incompleteThumbnail, boost::lambda::_2) 
 			)
 		);
 	}
