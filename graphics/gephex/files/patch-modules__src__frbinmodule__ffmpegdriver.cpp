--- modules/src/frbinmodule/ffmpegdriver.cpp.orig	2007-04-29 23:53:43.000000000 +0900
+++ modules/src/frbinmodule/ffmpegdriver.cpp	2008-08-09 19:14:24.000000000 +0900
@@ -20,6 +20,8 @@
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*/
 
+#define __STDC_CONSTANT_MACROS
+
 #include "ffmpegdriver.h"
 
 #include <string>
@@ -35,9 +37,12 @@
 #define EMULATE_INTTYPES
 #endif
 
-#include "avformat.h"
-#include "avcodec.h"
-#include "avutil.h"
+extern "C"
+{
+#include "avformat.h"
+#include "avcodec.h"
+#include "avutil.h"
+}
 
 #include "libscale.h"
 
@@ -239,7 +244,6 @@
     AVFormatParameters params;
     
     memset(&params, 0, sizeof(params));
-    params.image_format  = 0;
     params.initial_pause = 1;
 
     // open input file without format or bufffer size
