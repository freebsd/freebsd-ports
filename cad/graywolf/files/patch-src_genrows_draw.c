--- src/genrows/draw.c.orig	2018-08-23 20:02:57 UTC
+++ src/genrows/draw.c
@@ -1209,7 +1209,7 @@ process_graphics()
 	shortRowG = FALSE ;
 	remakerows() ;
 	draw_the_data() ;
-	if (last_chanceG) (VOID)last_chance() ;
+	if (last_chanceG) last_chance() ;
 
     }
 
