--- src/setup.c.orig	2011-05-04 00:15:43 UTC
+++ src/setup.c
@@ -64,7 +64,7 @@ along with this program.  If not, see <http://www.gnu.
 /* (These are now 'extern'd in "tuxmath.h") */
 
 
-SDL_Surface* screen;
+extern SDL_Surface* screen;
 SDL_Surface* images[NUM_IMAGES];
 sprite* sprites[NUM_SPRITES];
 /* Need special handling to generate flipped versions of images. This
