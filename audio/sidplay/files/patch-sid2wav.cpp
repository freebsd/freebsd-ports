--- sid2wav.cpp.orig
+++ sid2wav.cpp
@@ -18,9 +18,9 @@
 //  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 //
 
-#include <iostream.h>
-#include <iomanip.h>
-#include <fstream.h>
+#include <iostream>
+#include <iomanip>
+#include <fstream>
 #include <string.h>
 
 #include <stdlib.h>
@@ -39,6 +39,16 @@
 #include <sidplay/fformat.h>
 #include <sidplay/myendian.h>
 
+using std::cerr;
+using std::cout;
+using std::endl;
+using std::dec;
+using std::flush;
+using std::hex;
+using std::ios;
+using std::setfill;
+using std::setw;
+
 const char s2w_version[] = "1.8";
 
 struct wav_hdr                  // little endian
