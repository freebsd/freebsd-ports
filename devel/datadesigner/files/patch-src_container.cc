
$FreeBSD$

--- src/container.cc.orig	Sun Aug 22 21:54:00 2004
+++ src/container.cc	Sun Aug 22 21:54:09 2004
@@ -103,7 +103,7 @@
 	int		idx;
 	
 	count = m_project->GetChildrenCount(m_treeitemid, FALSE);
-	strings = new (wxString *) [count+1];
+	strings = new wxString * [count+1];
 	
 	idx = 0;
 	child = m_project->GetFirstChild(m_treeitemid, cookie);
