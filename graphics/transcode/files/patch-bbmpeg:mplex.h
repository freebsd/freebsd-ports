--- bbmpeg/mplex.h.orig	Thu Jan 30 19:26:07 2003
+++ bbmpeg/mplex.h	Thu Jan 30 19:26:18 2003
@@ -50,6 +50,8 @@
     Definitionen
 *************************************************************************/
 
+#include <sys/types.h>
+
 #define USER_DATA_START         0x000001b2
 #define SEQUENCE_HEADER 	0x000001b3
 #define SEQUENCE_END		0x000001b7
