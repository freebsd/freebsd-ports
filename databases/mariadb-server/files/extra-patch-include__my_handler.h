--- include/my_handler.h.orig	2012-08-30 21:44:42.000000000 +0200
+++ include/my_handler.h	2012-08-30 21:45:23.000000000 +0200
@@ -34,7 +34,7 @@
   But beware the dependency of HA_MAX_POSSIBLE_KEY_BUFF and HA_MAX_KEY_LENGTH.
 */
 
-#define HA_MAX_KEY_LENGTH           1000        /* Max length in bytes */
+#define HA_MAX_KEY_LENGTH           4000        /* Max length in bytes */
 #define HA_MAX_KEY_SEG              32          /* Max segments for key */
 
 #define HA_MAX_POSSIBLE_KEY_BUFF    (HA_MAX_KEY_LENGTH + 24+ 6+6) 
