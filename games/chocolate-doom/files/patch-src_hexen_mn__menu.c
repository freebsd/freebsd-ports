--- src/hexen/mn_menu.c.orig	2020-08-28 17:00:20 UTC
+++ src/hexen/mn_menu.c
@@ -131,7 +131,7 @@ boolean MenuActive;
 int InfoType;
 int messageson = true;
 boolean mn_SuicideConsole;
-boolean demoextend; // from h2def.h
+extern boolean demoextend; // from h2def.h
 
 // PRIVATE DATA DEFINITIONS ------------------------------------------------
 
