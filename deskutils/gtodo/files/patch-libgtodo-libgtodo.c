--- libgtodo/libgtodo.c.orig	Sun Feb 15 22:03:09 2004
+++ libgtodo/libgtodo.c	Sun Mar  7 21:58:55 2004
@@ -770,10 +770,10 @@
 GTodoClient * gtodo_client_new_default(GError **error)
 {
 	GError *tmp_error = NULL;
+	GTodoClient *cl = NULL;
 	/* check if the error is good or wrong. */
 	g_return_val_if_fail(error == NULL || *error == NULL,FALSE);
 
-	GTodoClient *cl = NULL;
 	cl = g_malloc(sizeof(GTodoClient));
 	cl->xml_path = g_strdup_printf("file:///%s/.gtodo/todos", g_getenv("HOME"));
 	/* check, open or create the correct xml file */
@@ -793,6 +793,7 @@
 GTodoClient * gtodo_client_new_from_file(char *filename, GError **error)
 {
 	GError *tmp_error = NULL;
+	GTodoClient *cl = NULL;
 	/* check if the error is good or wrong. */
 	g_return_val_if_fail(error == NULL || *error == NULL,FALSE);
 	if(debug)g_print("Trying to create a new client %s\n", filename);
@@ -802,7 +803,6 @@
 		g_propagate_error(error, tmp_error);
 		return NULL;	
 	}
-	GTodoClient *cl = NULL;
 	cl = g_malloc(sizeof(GTodoClient));
 	cl->xml_path = g_strdup(filename);
 	/* check, open or create the correct xml file */
@@ -832,12 +832,13 @@
 GTodoList * gtodo_client_get_category_list(GTodoClient *cl)
 {
 	xmlNodePtr  cur;
-	GTodoList *list = g_malloc(sizeof(GTodoList));
-	list->list = NULL;
 	int repos = 0;
+	GTodoCategory *cat;
+	GTodoList *list;
 	cl->number_of_categories = 0;
+	list = g_malloc(sizeof(GTodoList));
+	list->list = NULL;
 	cur = cl->root->xmlChildrenNode;
-	GTodoCategory *cat;
 
 	while(cur != NULL){
 		if(xmlStrEqual(cur->name, (const xmlChar *)"category")){
