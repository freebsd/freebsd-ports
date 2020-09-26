--- src/menu_lan.c.orig	2011-05-04 00:15:10 UTC
+++ src/menu_lan.c
@@ -37,7 +37,7 @@ along with this program.  If not, see <http://www.gnu.
 
 
 /* lan_player_type now defined in network.h */
-lan_player_type lan_player_info[MAX_CLIENTS];
+extern lan_player_type lan_player_info[MAX_CLIENTS];
 
 /* Local function prototypes: ------------------- */
 void draw_player_table(void);
