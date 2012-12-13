--- subcommander/ListWidget.cpp.orig	2009-09-13 01:49:22.000000000 +0900
+++ subcommander/ListWidget.cpp	2012-05-10 06:04:40.000000000 +0900
@@ -134,7 +134,7 @@
 "<b>help</b>"
 "<p>"
 "* pressing SHIFT-F1 in the working copy view will display a detailed"
-"description of the the columns and their possible values."
+" description of the the columns and their possible values."
 "</p>"
 "<b>internationalization (i18n)</b>"
 "<p>"
@@ -151,6 +151,8 @@
 "set any repository folder as branch or tag folder. subcommander needs"
 " only to know WHERE you keep your branches and tags. It does NOT "
 "require that they are named 'branches' or 'tags'."
+"<br>* for anonymous (read only) access to the preconfigured subcommander"
+"  repository, use the username 'guest' with an empty password."
 "</p>"
 "</qt>"
 );
