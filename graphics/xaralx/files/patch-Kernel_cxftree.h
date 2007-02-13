--- Kernel/cxftree.h.orig	Tue Feb 13 10:21:18 2007
+++ Kernel/cxftree.h	Tue Feb 13 10:21:40 2007
@@ -287,7 +287,7 @@
 
 	INT32 AddDisplayNode(CXFNode* pNode,INT32 Index,INT32 Depth,BOOL ExpandAll);
 	void ShowNodeDebugInfoForNode(CXFNode *pNode);
-	CXaraFileRecordHandler* CXFTreeDlg::FindHandler(UINT32 Tag);
+	CXaraFileRecordHandler* FindHandler(UINT32 Tag);
 	void GetTagText(CXFNode* pNode,String_256& Str);
 
 	CXFNode* pRoot;
