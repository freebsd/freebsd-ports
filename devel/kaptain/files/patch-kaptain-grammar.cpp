--- kaptain/grammar.cpp.orig	Wed Aug 14 12:13:38 2002
+++ kaptain/grammar.cpp	Fri Dec 20 16:14:31 2002
@@ -878,7 +878,7 @@
 }
 
 
-void Rule::send(string message, bool prefix_sender=true)
+void Rule::send(string message, bool prefix_sender)
 {
   string total;
   if (prefix_sender)
