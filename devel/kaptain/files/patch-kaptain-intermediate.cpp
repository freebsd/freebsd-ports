--- kaptain/intermediate.cpp.orig	Wed Aug 14 12:14:52 2002
+++ kaptain/intermediate.cpp	Fri Dec 20 16:14:31 2002
@@ -552,7 +552,7 @@
 
 
 
-void Intermediate::send(string message, char separ=':')
+void Intermediate::send(string message, char separ)
 {
   if (is_special() && father)
     /* send throuh SPEC's father */
