--- src/Menu/ListGamesState.cpp.orig	2019-08-03 22:29:28 UTC
+++ src/Menu/ListGamesState.cpp
@@ -17,6 +17,7 @@
  * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
  */
 #include "ListGamesState.h"
+#include <algorithm>
 #include <utility>
 #include "../Engine/Logger.h"
 #include "../Savegame/SavedGame.h"
