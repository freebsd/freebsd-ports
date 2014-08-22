--- utils/zStreamBufferImplZLib.cpp.orig
+++ utils/zStreamBufferImplZLib.cpp
@@ -12,6 +12,8 @@
 // ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 // FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details
 //
+#include <cstdlib>
+
 #include <Trace.hpp>
 #include <zStreamBufferImplZLib.hpp>
 
