--- ccx_2.12/src/CalculiX.h.orig	2017-04-02 12:59:25 UTC
+++ ccx_2.12/src/CalculiX.h
@@ -15,12 +15,14 @@
 /*     along with this program; if not, write to the Free Software       */
 /*     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.         */
 
-#define Linux 1
+#include <pthread.h>
+
+#define FreeBSD 1
 #define IRIX 2
 #define IRIX64 3
 #define HP 4
 
-#if ARCH == Linux
+#if ARCH == FreeBSD
 #define FORTRAN(A,B) A##_  B
 #elif ARCH == IRIX || ARCH == IRIX64
 #define FORTRAN(A,B) A##_##B
@@ -28,7 +30,7 @@
 #define FORTRAN(A,B) A##B
 #endif
 
-#if ARCH == Linux
+#if ARCH == FreeBSD
 #define CEE(A,B) A##_  B
 #elif ARCH == IRIX || ARCH == IRIX64
 #define CEE(A,B) A##_##B
