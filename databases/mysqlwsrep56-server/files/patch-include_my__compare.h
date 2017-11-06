--- include/my_compare.h.orig	2011-05-10 09:46:46.000000000 +0200
+++ include/my_compare.h	2011-05-10 09:47:01.000000000 +0200
@@ -39,7 +39,7 @@
   But beware the dependency of MI_MAX_POSSIBLE_KEY_BUFF and HA_MAX_KEY_LENGTH.
 */
 
-#define HA_MAX_KEY_LENGTH           1000        /* Max length in bytes */
+#define HA_MAX_KEY_LENGTH           4000        /* Max length in bytes */
 #define HA_MAX_KEY_SEG              16          /* Max segments for key */
 
 #define HA_MAX_POSSIBLE_KEY_BUFF    (HA_MAX_KEY_LENGTH + 24+ 6+6)
