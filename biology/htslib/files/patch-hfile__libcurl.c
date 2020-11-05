--- hfile_libcurl.c.orig	2020-09-22 12:15:49 UTC
+++ hfile_libcurl.c
@@ -22,6 +22,10 @@ LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR O
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.  */
 
+#ifndef ENOTRECOVERABLE
+#define ENOTRECOVERABLE EIO
+#endif
+
 #define HTS_BUILDING_LIBRARY // Enables HTSLIB_EXPORT, see htslib/hts_defs.h
 #include <config.h>
 
@@ -73,6 +77,10 @@ typedef struct {
     unsigned int num;
     unsigned int size;
 } hdrlist;
+
+#ifndef ENOTRECOVERABLE
+#define ENOTRECOVERABLE EIO
+#endif
 
 typedef struct {
     hdrlist fixed;                   // List of headers supplied at hopen()
