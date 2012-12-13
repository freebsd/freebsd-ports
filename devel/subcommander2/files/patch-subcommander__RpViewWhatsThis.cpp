--- subcommander/RpViewWhatsThis.cpp.orig	2007-06-26 04:28:49.000000000 +0900
+++ subcommander/RpViewWhatsThis.cpp	2012-05-10 05:47:04.000000000 +0900
@@ -19,7 +19,7 @@
   ws += "<b>" + _q("repository copy view columns") + "</b>";
   ws += 
      "<hr>"
-     "<table cellspacing=0>"
+     "<table cellspacing=2>"
       "<tr>";
   ws += "<td><nobr>" + _q("name") + "</nobr></td>";
   ws += "<td>" + _q("the name of an item - the header shows its name and the repository url") + "<br></td>"
@@ -51,7 +51,7 @@
   ws += "<td><nobr>" + _q("last committed date") + "</nobr></td>";
   ws += "<td>" + _q("an items last committed date") + "<br></td>" +
       "</tr>"
-      "<tr>";
+      "<tr>"
      "</table>"
     "</qt>";
 
