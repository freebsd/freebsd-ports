Index: qemu/audio/ossaudio.c
@@ -21,8 +21,8 @@
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  * THE SOFTWARE.
  */
-#include <sys/mman.h>
 #include <sys/types.h>
+#include <sys/mman.h>
 #include <sys/ioctl.h>
 #include <sys/soundcard.h>
 #include <assert.h>
