--- engine/liberty.h.orig	2020-08-25 08:52:13 UTC
+++ engine/liberty.h
@@ -856,10 +856,6 @@ struct worm_data {
 
 extern struct worm_data worm[BOARDMAX];
 
-/* Unconditionally meaningless moves. */
-int meaningless_black_moves[BOARDMAX];
-int meaningless_white_moves[BOARDMAX];
-
 /* Surround cache (see surround.c) */
 
 #define MAX_SURROUND 10
