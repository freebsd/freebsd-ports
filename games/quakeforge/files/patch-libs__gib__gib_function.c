--- ./libs/gib/gib_function.c.orig	Fri Apr  9 15:18:19 2004
+++ ./libs/gib/gib_function.c	Sun Dec 17 15:57:10 2006
@@ -169,7 +169,7 @@
 	gib_var_t  *var;
 	static char argss[] = "args";
 
-	static qboolean 
+	qboolean 
 	iterate (char *arg, llist_node_t *node)
 	{	
 		var = GIB_Var_Get_Complex (&GIB_DATA(cbuf)->locals, &zero,
@@ -207,7 +207,7 @@
 	gib_var_t  *var;
 	static char argss[] = "args";
 
-	static qboolean 
+	qboolean 
 	iterate (char *arg, llist_node_t *node)
 	{	
 		var = GIB_Var_Get_Complex (&GIB_DATA(cbuf)->locals, &zero,
