--- src/editor/editor_screen.hpp.orig	2007-09-30 20:07:08.000000000 +0400
+++ src/editor/editor_screen.hpp	2013-08-23 23:08:40.689231327 +0400
@@ -27,7 +27,7 @@
 
 class DrawingContext;
 class FileDialog;
-class GUI::GUIManager;
+namespace GUI { class GUIManager; }
 class Pathname;
 
 namespace Editor {
