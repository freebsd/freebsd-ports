--- main.cc.orig	Wed Apr 11 21:12:20 2001
+++ main.cc	Sun Dec 14 18:17:33 2003
@@ -1,3 +1,4 @@
+#define filename_setext fl_filename_setext
 #include "bebac.h"
 #include "qsort.h"
 #include "komande.h"
@@ -18,7 +19,7 @@
 extern "C" {
 	char *intern_filename(char *,const char *); extern char *home_dir;
 	char *fn_format(char *to,const char *name,const char *dsk,const char *form,int flag);
-	void load_defaults(const char *conf_file, const char **groups, int *argc, char ***argv);
+	int load_defaults(const char *conf_file, const char **groups, int *argc, char ***argv);
 	void free_defaults(char **argv);
 	void mysql_read_default_options(struct st_mysql_options *options,  const char *filename,const char *group);
 	int strcasecmp(const char *,const char *);
@@ -461,7 +462,7 @@
 }
 
 static void if_conn (void) {
-  unsigned int j = 0, counter = 0;  c_info=con->clinet_info(); s_info=con->server_info();
+  unsigned int j = 0, counter = 0;  c_info=con->client_info(); s_info=con->server_info();
   try {
 		Query query = con->query(); if (ldb) {ddd=(string)ldb; ldb=(char*)ddd.c_str();}
     query << "show databases";
@@ -526,7 +527,7 @@
 			tables.insert(tables.end(),xx);
 		}
 		qSortHelp (0, (size_t) tables.size(), Fcmp, Exchange); 	
-		ldb = (char *)databases[j].c_str(); c_info=con->clinet_info(); s_info=con->server_info();
+		ldb = (char *)databases[j].c_str(); c_info=con->client_info(); s_info=con->server_info();
 		b_connect->set();    down_group->activate();  query_browser->activate();
 		if (databases.size()) choice_db->activate();  choice_db->redraw(); 
 		; if (query_menus) hier->activate();
