--- src/fcdump/demangle.h.orig	2021-05-10 22:03:39 UTC
+++ src/fcdump/demangle.h
@@ -16,8 +16,9 @@
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.  */
+#include <libiberty/demangle.h>
 
-#if !defined (DEMANGLE_H)
+#if 0
 #define DEMANGLE_H
 
 #include <ansidecl.h>
