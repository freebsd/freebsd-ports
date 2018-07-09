--- CalculiX.h.orig	2018-04-28 14:05:18 UTC
+++ CalculiX.h
@@ -16,12 +16,14 @@
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
@@ -29,7 +31,7 @@
 #define FORTRAN(A,B) A##B
 #endif
 
-#if ARCH == Linux
+#if ARCH == FreeBSD
 #define CEE(A,B) A##_  B
 #elif ARCH == IRIX || ARCH == IRIX64
 #define CEE(A,B) A##_##B
