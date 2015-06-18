--- plugins/collab/backends/sipsimple/xp/SIPSimpleBuddy.h.orig	2015-04-04 04:57:15 UTC
+++ plugins/collab/backends/sipsimple/xp/SIPSimpleBuddy.h
@@ -52,10 +52,10 @@ public:
 
 	virtual const DocTreeItem* getDocTreeItems() const
 	{
-		const vector<DocHandle*>& docHandles = getDocHandles();
+		const std::vector<DocHandle*>& docHandles = getDocHandles();
 		DocTreeItem* first = 0;
 		DocTreeItem* prev = 0;
-		for (vector<DocHandle*>::const_iterator pos = docHandles.begin(); pos != docHandles.end(); pos++)
+		for (std::vector<DocHandle*>::const_iterator pos = docHandles.begin(); pos != docHandles.end(); pos++)
 		{
 			DocTreeItem* item = new DocTreeItem();
 			item->m_type = DOCTREEITEM_TYPE_DOCUMENT;
