--- ccx_2.6.1/src/CalculiX.h.orig	2012-10-06 08:13:06.000000000 -0500
+++ ccx_2.6.1/src/CalculiX.h	2013-03-04 15:33:04.000000000 -0500
@@ -15,6 +15,8 @@
 /*     along with this program; if not, write to the Free Software       */
 /*     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.         */
 
+#include <pthread.h>
+
 #define Linux 1
 #define IRIX 2
 #define IRIX64 3
@@ -26,6 +28,8 @@
 #define FORTRAN(A,B) A##_##B
 #elif ARCH == HP
 #define FORTRAN(A,B) A##B
+#else
+#define FORTRAN(A,B) A##_ B
 #endif
 
 #define NNEW(a,b) (a *)u_calloc((b),sizeof(a))
