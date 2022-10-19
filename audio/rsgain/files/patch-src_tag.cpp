/wrkdirs/usr/ports/audio/rsgain/work/rsgain-3.0.1/src/tag.cpp:254:5: error: no member named 'round' in namespace 'std'
    GAIN_TO_Q78(track.result.album_gain) : GAIN_TO_Q78(track.result.track_gain);
    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/wrkdirs/usr/ports/audio/rsgain/work/rsgain-3.0.1/src/tag.hpp:35:38: note: expanded from macro 'GAIN_TO_Q78'
#define GAIN_TO_Q78(gain) (int) std::round(gain * 256.f)
                                ~~~~~^

--- src/tag.cpp.orig	2022-10-19 02:49:19 UTC
+++ src/tag.cpp
@@ -28,7 +28,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include <math.h>
+#include <cmath>
 #include <stdio.h>
 #include <string.h>
 #include <string>
@@ -506,4 +506,4 @@ void taglib_get_version(std::string &buffer)
 void taglib_get_version(std::string &buffer)
 {
     buffer = fmt::format("{}.{}.{}", TAGLIB_MAJOR_VERSION, TAGLIB_MINOR_VERSION, TAGLIB_PATCH_VERSION);
-}
\ No newline at end of file
+}
