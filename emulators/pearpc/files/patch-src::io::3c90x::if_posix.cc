--- src/io/3c90x/if_posix.cc.orig	Sat May  8 03:27:32 2004
+++ src/io/3c90x/if_posix.cc	Sat May 22 13:12:17 2004
@@ -20,6 +20,9 @@
  *	along with this program; if not, write to the Free Software
  *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
+
+#define WIN32 /* Dirty hack  :-) */
+
 #if defined(WIN32) || defined(__WIN32__)
 #else
 
