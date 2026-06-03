--- libgda/sql-parser/lemon.c.orig	2020-11-08 20:23:20 UTC
+++ libgda/sql-parser/lemon.c
@@ -69,14 +69,6 @@ static struct action *Action_sort(struct action *);
 static struct action *Action_new(void);
 static struct action *Action_sort(struct action *);
 
-/********** From the file "build.h" ************************************/
-void FindRulePrecedences();
-void FindFirstSets();
-void FindStates();
-void FindLinks();
-void FindFollowSets();
-void FindActions();
-
 /********* From the file "configlist.h" *********************************/
 void Configlist_init(void);
 struct config *Configlist_add(struct rule *, int);
