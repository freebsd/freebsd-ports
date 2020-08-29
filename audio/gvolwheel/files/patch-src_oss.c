--- src/oss.c.orig	2012-04-07 21:18:50 UTC
+++ src/oss.c
@@ -17,13 +17,15 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#include <linux/soundcard.h>
+#include <sys/unistd.h>
+#include <sys/soundcard.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 
 #include "oss.h"
 
 static char *default_device = "/dev/mixer"; 
+struct stereo_volume oss_vol;
 
 int mixer_fd;
 
@@ -38,17 +40,17 @@ int vol_backend_init (char *device)
 int vol_backend_get(int mixer)
 {
 	if (mixer == 0)
-		ioctl(mixer_fd, MIXER_READ(SOUND_MIXER_VOLUME), &vol);
+		ioctl(mixer_fd, MIXER_READ(SOUND_MIXER_VOLUME), &oss_vol);
 	else if (mixer == 1)	
-		ioctl(mixer_fd, MIXER_READ(SOUND_MIXER_PCM), &vol);
-	return(vol.left);
+		ioctl(mixer_fd, MIXER_READ(SOUND_MIXER_PCM), &oss_vol);
+	return(oss_vol.left);
 }
 
 void vol_backend_set(int mixer, int value)
 {
-	vol.left=vol.right = value;
+	oss_vol.left=oss_vol.right = value;
 	if (mixer == 0)	
-		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_VOLUME), &vol);
+		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_VOLUME), &oss_vol);
 	else if (mixer == 1)	
-		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_PCM), &vol);
-}
\ No newline at end of file
+		ioctl(mixer_fd, MIXER_WRITE(SOUND_MIXER_PCM), &oss_vol);
+}
