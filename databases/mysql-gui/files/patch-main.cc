--- main.cc.orig	Sat Aug 18 18:18:16 2001
+++ main.cc	Sat Aug 18 09:57:03 2001
@@ -461,7 +461,7 @@
 }
 
 static void if_conn (void) {
-  unsigned int j = 0, counter = 0;  c_info=con->clinet_info(); s_info=con->server_info();
+  unsigned int j = 0, counter = 0;  c_info=con->client_info(); s_info=con->server_info();
   try {
 		Query query = con->query(); if (ldb) {ddd=(string)ldb; ldb=(char*)ddd.c_str();}
     query << "show databases";
@@ -526,7 +526,7 @@
 			tables.insert(tables.end(),xx);
 		}
 		qSortHelp (0, (size_t) tables.size(), Fcmp, Exchange); 	
-		ldb = (char *)databases[j].c_str(); c_info=con->clinet_info(); s_info=con->server_info();
+		ldb = (char *)databases[j].c_str(); c_info=con->client_info(); s_info=con->server_info();
 		b_connect->set();    down_group->activate();  query_browser->activate();
 		if (databases.size()) choice_db->activate();  choice_db->redraw(); 
 		; if (query_menus) hier->activate();
