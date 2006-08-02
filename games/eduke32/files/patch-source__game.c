--- source/game.c.orig	Tue Jul 18 16:14:46 2006
+++ source/game.c	Wed Aug  2 01:12:20 2006
@@ -8887,7 +8887,7 @@
 
     i = CONFIG_ReadSetup();
 
-#if defined RENDERTYPEWIN || (defined RENDERTYPESDL && !defined __APPLE__ && defined HAVE_GTK2)
+#if 0
     if (i < 0 || ForceSetup || CommandSetup) {
         if (quitevent || !startwin_run()) {
             uninitengine();
