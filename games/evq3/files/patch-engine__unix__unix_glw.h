--- ./engine/unix/unix_glw.h.orig	Sat Dec 16 17:32:42 2006
+++ ./engine/unix/unix_glw.h	Tue Apr 17 00:00:09 2007
@@ -19,7 +19,7 @@
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 ===========================================================================
 */
-#if !( defined __linux__ || defined __FreeBSD__ || defined __sun || defined MACOS_X )
+#if !( defined __unix__ || defined __sun || defined MACOS_X )
 #error You should include this file only on Linux/FreeBSD/Solaris platforms
 #endif
 
