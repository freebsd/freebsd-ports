--- include/my_compare.h.orig	2019-09-20 08:30:51 UTC
+++ include/my_compare.h
@@ -49,7 +49,7 @@
   But beware the dependency of MI_MAX_POSSIBLE_KEY_BUFF and HA_MAX_KEY_LENGTH.
 */
 
-#define HA_MAX_KEY_LENGTH 1000 /* Max length in bytes */
+#define HA_MAX_KEY_LENGTH 4000 /* Max length in bytes */
 #define HA_MAX_KEY_SEG 16      /* Max segments for key */
 
 #define HA_MAX_POSSIBLE_KEY_BUFF (HA_MAX_KEY_LENGTH + 24 + 6 + 6)
