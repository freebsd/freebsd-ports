
$FreeBSD$

--- src/servers/dbserver.cc.orig	Sun Aug 22 21:52:56 2004
+++ src/servers/dbserver.cc	Sun Aug 22 21:53:09 2004
@@ -181,7 +181,7 @@
 	wxDBServerListNode	*node;
 	int			idx = 0;
 	
-	names = new (wxString)[g_dbserverlist->GetCount()];
+	names = new wxString[g_dbserverlist->GetCount()];
 	
 	node = g_dbserverlist->GetFirst();
 	while (node) {
