--- include/myisam.h.orig	2021-12-17 16:07:27 UTC
+++ include/myisam.h
@@ -60,7 +60,7 @@
   The following defines can be increased if necessary.
   But beware the dependency of MI_MAX_POSSIBLE_KEY_BUFF and MI_MAX_KEY_LENGTH.
 */
-#define MI_MAX_KEY_LENGTH 1000 /* Max length in bytes */
+#define MI_MAX_KEY_LENGTH 4000 /* Max length in bytes */
 #define MI_MAX_KEY_SEG 16      /* Max segments for key */
 
 #define MI_MAX_KEY_BUFF (MI_MAX_KEY_LENGTH + MI_MAX_KEY_SEG * 6 + 8 + 8)
