--- game/main.cpp.orig	Fri Jan  2 18:26:21 2004
+++ game/main.cpp	Fri Jan  2 18:26:37 2004
@@ -12,7 +12,7 @@
 // ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 // FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details
 //
-#include "SDL.h" //needed for SDL_main
+#include <SDL11/SDL.h> //needed for SDL_main
 
 #include <Trace.hpp>
 #include <Constants.hpp>
@@ -46,7 +46,7 @@
 }
 
 #include <png.h>
-#include <SDL/SDL_mixer.h>
+#include <SDL11/SDL_mixer.h>
 void showVersions( void)
 {
     const SDL_version *vsdl = SDL_Linked_Version();
