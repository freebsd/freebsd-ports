--- wordwarvi.c.orig	2016-03-11 15:16:11 UTC
+++ wordwarvi.c
@@ -11559,12 +11559,14 @@ void start_level()
 	srandom(level.random_seed);
 	generate_terrain(&terrain);
 
+#if 0
 	add_buildings(&terrain);/* Some FreeBSD users report that */
 				/*add_buildings() causes crashes. */
 				/* Commenting this out on FreeBSD */
 				/* may help, but, no buildings. */
 				/* I've looked at the code, but */
 				/* don't see anything wrong with it. */
+#endif
 	add_humanoids(&terrain);
 	add_bridges(&terrain);
 	add_socket(&terrain);
