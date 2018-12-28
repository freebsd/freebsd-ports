If this is not defined, libavutil/common.h fails because of this check:

#if defined(__cplusplus) && !defined(__STDC_CONSTANT_MACROS) && !defined(UINT64_C)
#error missing -D__STDC_CONSTANT_MACROS / #define __STDC_CONSTANT_MACROS
#endif

Not submitted upstream, as newer releases build with -std=c++0x, which always
sets __STD_CONSTANT_MACROS by default.
--- src/musicbrainz/MusicDNSAudioDecoder.cpp.orig	2013-08-14 20:22:52 UTC
+++ src/musicbrainz/MusicDNSAudioDecoder.cpp
@@ -14,6 +14,8 @@
  * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
  ****************************************************************************************/
 
+#define __STDC_CONSTANT_MACROS
+
 #define DEBUG_PREFIX "MusicDNSAudioDecoder"
 
 #include "MusicDNSAudioDecoder.h"
