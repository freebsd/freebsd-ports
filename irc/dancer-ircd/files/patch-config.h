--- include/config.h.orig	Sun Feb 15 02:11:26 2004
+++ include/config.h	Tue Apr 20 00:29:14 2004
@@ -66,8 +66,8 @@
  * system limits. If you know what you are doing, increase them now
  */
 
-#define HARD_FDLIMIT_   256 /* was 256 */
-#define INIT_MAXCLIENTS 200 /* was 200 */
+#define HARD_FDLIMIT_   512 /* was 256 */
+#define INIT_MAXCLIENTS 400 /* was 200 */
 
 /*
  * This is how many 'buffer connections' we allow... 
