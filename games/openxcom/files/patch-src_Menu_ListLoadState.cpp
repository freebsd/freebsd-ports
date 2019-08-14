--- src/Menu/ListLoadState.cpp.orig	2019-08-03 22:27:50 UTC
+++ src/Menu/ListLoadState.cpp
@@ -16,6 +16,7 @@
  * You should have received a copy of the GNU General Public License
  * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
  */
+#include <algorithm>
 #include "ListLoadState.h"
 #include "../Engine/Game.h"
 #include "../Engine/Language.h"
