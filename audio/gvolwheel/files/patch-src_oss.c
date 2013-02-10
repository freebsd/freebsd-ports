--- src/oss.c.orig	2013-02-05 00:07:25.250545453 +0400
+++ src/oss.c	2013-02-05 00:08:55.817607467 +0400
@@ -17,7 +17,8 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#include <linux/soundcard.h>
+#include <sys/unistd.h>
+#include <sys/soundcard.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 
@@ -51,4 +52,4 @@
 		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_VOLUME), &vol);
 	else if (mixer == 1)	
 		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_PCM), &vol);
-}
\ No newline at end of file
+}
