
$FreeBSD$

--- docs/gnome-help/sgmldocs.make	2002/08/28 07:10:39	1.1
+++ docs/gnome-help/sgmldocs.make	2002/08/28 07:11:11
@@ -32,7 +32,7 @@
 #   dist-hook: app-dist-hook
 #
 
-docdir = $(datadir)/gnome/help/$(docname)/$(lang)
+docdir = $(datadir)/help/$(docname)/$(lang)
 
 doc_DATA = index.html
 
