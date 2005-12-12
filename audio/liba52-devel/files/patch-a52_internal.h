--- a52_internal.h.orig	Sun Dec 11 01:58:58 2005
+++ a52_internal.h	Sun Dec 11 02:47:04 2005
@@ -21,6 +21,15 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#ifndef __LIBA52__52_internal_h__
+# define __LIBA52__52_internal_h__
+
+#include <inttypes.h>
+
+#ifndef NULL
+# define NULL 0
+#endif
+
 typedef struct {
     uint8_t bai;		/* fine SNR offset, fast gain */
     uint8_t deltbae;		/* delta bit allocation exists */
@@ -87,6 +96,8 @@
     int downmixed;
 };
 
+typedef struct a52_state_s a52_state_t;
+
 #define LEVEL_PLUS6DB 2.0
 #define LEVEL_PLUS3DB 1.4142135623730951
 #define LEVEL_3DB 0.7071067811865476
@@ -160,3 +171,5 @@
 #define BIAS(x) (x)
 
 #endif
+
+#endif /* __LIBA52__52_internal_h__ */
