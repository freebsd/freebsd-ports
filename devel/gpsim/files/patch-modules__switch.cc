--- modules/switch.cc.orig
+++ modules/switch.cc
@@ -582,7 +582,7 @@
 
   //========================================================================
 
-  Switch::Switch(const char *_new_name=0)
+  Switch::Switch(const char *_new_name)
     : SwitchBase(_new_name, "\
 Two port switch\n\
  Attributes:\n\
