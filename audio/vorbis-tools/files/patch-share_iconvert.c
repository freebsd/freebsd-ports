
$FreeBSD$

--- share/iconvert.c.orig
+++ share/iconvert.c
@@ -16,6 +16,10 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#ifdef HAVE_CONFIG_H
+# include <config.h>
+#endif
+
 #ifdef HAVE_ICONV
 
 #include <assert.h>
