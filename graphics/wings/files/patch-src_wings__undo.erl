--- src/wings_undo.erl.orig	2015-06-24 22:27:33 UTC
+++ src/wings_undo.erl
@@ -30,12 +30,12 @@
 	 
 %% The essential part of the state record.
 -record(est,
-	{shapes=[] :: list(#we{}) | gb_tree(),
+	{shapes=[] :: list(#we{}) | gb_trees:tree(),
 	 selmode=face :: sel_mode(),
 	 sel=[] :: list(),
 	 onext=1 :: elem_num(),
 	 mat=wings_material:default(),
-	 pst=gb_trees:empty() :: gb_tree(),
+	 pst=gb_trees:empty() :: gb_trees:tree(),
 
 	 %% For the Develop menu.
 	 cmd,
