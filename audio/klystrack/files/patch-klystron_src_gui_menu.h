--- klystron/src/gui/menu.h.orig	2021-01-17 17:28:54 UTC
+++ klystron/src/gui/menu.h
@@ -25,7 +25,7 @@ FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 OTHER DEALINGS IN THE SOFTWARE.
 */
 
-struct menu_t
+extern struct menu_t
 {
 	int flags;
 	const struct menu_t *parent;
