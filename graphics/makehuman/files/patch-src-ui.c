--- src/ui.c.orig	Mon Mar  6 12:20:35 2006
+++ src/ui.c	Mon Mar  6 12:21:13 2006
@@ -502,6 +502,7 @@
     while(Panels[i].Button[c].id != -1)
     {
       Panels[i].Button[c].id = d;
+      {
 #ifdef HAVE_CONFIG_H
       char tmp[MAX_PATH];
       strcpy (tmp, PACKAGE_DATA_DIR"/");
@@ -510,6 +511,7 @@
 #else
       if(Panels[i].Button[c].image) Panels[i].Button[c].texture = load_texture(Panels[i].Button[c].image);
 #endif
+      }
       c++;
       d++;
     }
