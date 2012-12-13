--- subcommander/DiffViewModel.cpp.orig	2008-12-31 00:58:11.000000000 +0900
+++ subcommander/DiffViewModel.cpp	2012-05-10 05:50:30.000000000 +0900
@@ -78,7 +78,7 @@
 {
 public:
   DiffThread( ScModel* model, DiffViewModel::DiffCmds& cmds )
-    : _model(model), _cmds(cmds), _run(true)
+    : _run(true), _model(model), _cmds(cmds)
   {
   }
   
