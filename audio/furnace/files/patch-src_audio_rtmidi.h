--- src/audio/rtmidi.h.orig	2025-04-06 15:53:42 UTC
+++ src/audio/rtmidi.h
@@ -17,7 +17,7 @@
  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
-#include "../../extern/rtmidi/RtMidi.h"
+#include "rtmidi/RtMidi.h"
 #include "taAudio.h"
 
 class TAMidiInRtMidi: public TAMidiIn {
@@ -51,4 +51,4 @@ class TAMidiOutRtMidi: public TAMidiOut {
       port(NULL),
       isOpen(false),
       isWorking(false) {}
-};
\ No newline at end of file
+};
