--- include/config.h.orig	Wed Sep  3 03:11:17 2003
+++ include/config.h	Fri Nov 14 06:16:38 2003
@@ -36,8 +36,8 @@
  * system limits. If you know what you are doing, increase them now
  */
 
-#define HARD_FDLIMIT_   4096 /* was 256 */
-#define INIT_MAXCLIENTS 4000 /* was 200 */
+#define HARD_FDLIMIT_   512 /* was 256 */
+#define INIT_MAXCLIENTS 400 /* was 200 */
 
 /*
  * This is how many 'buffer connections' we allow... 
