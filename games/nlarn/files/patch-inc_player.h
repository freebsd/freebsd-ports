--- inc/player.h.orig	2020-05-23 06:13:27 UTC
+++ inc/player.h
@@ -79,9 +79,6 @@ typedef enum _player_sex
     PS_MAX
 } player_sex;
 
-/* textual representation of the player's gender */
-const char *player_sex_str[PS_MAX];
-
 typedef struct _player_settings
 {
     gboolean auto_pickup[IT_MAX]; /* automatically pick up item of enabled types */
