--- modules/logic.cc.orig	2015-06-11 02:17:18 UTC
+++ modules/logic.cc
@@ -269,8 +269,10 @@ LogicGate::LogicGate(const char *name, c
 
 LogicGate::~LogicGate()
 {
+#ifdef HAVE_GUI
   if (pixbuf)
     g_object_unref(pixbuf);
+#endif
 }
 
 //--------------------------------------------------------------
