--- wiz-you.cc.orig	2016-06-29 18:11:14 UTC
+++ wiz-you.cc
@@ -1126,6 +1126,7 @@ void wizard_join_religion()
     }
 }
 
+#ifdef WIZARD
 void wizard_xom_acts()
 {
     char specs[80];
@@ -1158,3 +1159,4 @@ void wizard_xom_acts()
     dprf("Okay, Xom is doing '%s'.", xom_effect_to_name(event).c_str());
     xom_take_action(event, severity);
 }
+#endif
