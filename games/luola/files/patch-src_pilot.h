--- src/pilot.h.orig	2022-07-02 17:04:35 UTC
+++ src/pilot.h
@@ -34,7 +34,7 @@ struct Ship;
 
 #define PARACHUTE_FRAME 2
 
-struct Pilot {
+extern struct Pilot {
     struct Walker walker;       /* inherits Walker */
     SDL_Surface *sprite[3];     /* Normal,Normal2, Parachute */
     Vector attack_vector;       /* Direction where gun is pointed to */
