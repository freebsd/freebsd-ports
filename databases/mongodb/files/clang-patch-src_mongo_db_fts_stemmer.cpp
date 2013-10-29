--- src/mongo/db/fts/stemmer.cpp.orig	2013-10-14 09:21:23.732674604 +0000
+++ src/mongo/db/fts/stemmer.cpp	2013-10-14 09:21:35.339894547 +0000
@@ -16,6 +16,7 @@
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <cstdlib>
 #include <string>
 
 #include "mongo/db/fts/stemmer.h"
