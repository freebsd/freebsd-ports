--- src/oss.c.orig	2012-04-07 21:18:50 UTC
+++ src/oss.c
@@ -17,7 +17,8 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#include <linux/soundcard.h>
+#include <sys/unistd.h>
+#include <sys/soundcard.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 
@@ -51,4 +52,4 @@ void vol_backend_set(int mixer, int valu
 		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_VOLUME), &vol);
 	else if (mixer == 1)	
 		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_PCM), &vol);
-}
\ No newline at end of file
+}
