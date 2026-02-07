--- src/mapline.c.orig	2018-01-02 05:18:40 UTC
+++ src/mapline.c
@@ -60,6 +60,8 @@ static int antmap = 1;
 
 /******************************************************************************
                                                                 MAPLINEINIT  */
+char * tag (char []);
+
 int maplineInit (sourcename, ifdefp) char *sourcename; void *ifdefp;
 {
   obstack_init (&osMap);
