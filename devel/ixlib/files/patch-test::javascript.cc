--- test/javascript.cc.orig	Fri Nov 28 12:57:33 2003
+++ test/javascript.cc	Fri Nov 28 13:15:30 2003
@@ -64,7 +64,7 @@
 
 
 // simple call-in example -----------------------------------------------------
-IXLIB_JS_DECLARE_FUNCTION(write) {
+IXLIB_JS_DECLARE_FUNCTION(write_) {
   FOREACH_CONST(first,parameters,parameter_list)
     cout << (*first)->toString();
   return makeNull();
@@ -99,7 +99,7 @@
     // end complex call-in example --------------------------------------------
     
     // simple call-in example -------------------------------------------------
-    ev = new write;
+    ev = new write_;
     ip.RootScope->addMember("write",ev);
     // end simple call-in example ---------------------------------------------
 
