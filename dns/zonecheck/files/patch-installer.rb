--- installer.rb.orig	Mon Oct 27 17:42:01 2003
+++ installer.rb	Tue Nov  4 13:06:14 2003
@@ -190,8 +190,6 @@
     def rule_all
 	inst_common ; patch_common 
 	inst_cli
-	inst_cgi    ; patch_cgi
-	inst_doc
     end
     def rule_cli
 	inst_common ; patch_common
