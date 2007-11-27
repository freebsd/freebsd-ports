--- sim/comptypes.c.orig	2007-11-23 23:17:42.000000000 +0100
+++ sim/comptypes.c	2007-11-23 23:18:07.000000000 +0100
@@ -96,5 +96,5 @@
 	    stopper_p},
 	{"LINK_COST_FUNC",	AUXILIARY_CLASS,lcostfcn_action,	
 	    link_cost_func_p},
-	{"", NULL} /* This line indicates the end of the list.  */
+	{"", 0} /* This line indicates the end of the list.  */
 };
