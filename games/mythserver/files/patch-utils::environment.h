--- utils/environment.h.orig	Sat Feb  9 15:43:33 2002
+++ utils/environment.h	Sat Feb  9 15:52:31 2002
@@ -16,9 +16,9 @@
 	
 	#ifdef BN2_FULLVERSION
 		#define BUNGIE_NET_ADMINISTRATOR			"nobody"
-		#define METASERVER_ROOT_DIR					"C:\\WINNT"
-		#define MOTD_FILE_NAME						"motd"
-		#define UPGRADE_PORT						"-1" // obsolete
+		#define METASERVER_ROOT_DIR		"/usr/local/share/mythserver"
+		#define MOTD_FILE_NAME			"motd"
+		#define UPGRADE_PORT			"-1" // obsolete
 		#ifndef USERD_HOST
 			#warning USERD_HOST set to <insert your static ip here>
 			#define USERD_HOST						"127.0.0.1" // <insert your static ip here>
@@ -27,29 +27,29 @@
 		#define USERD_ROOM_PORT						"6323"
 		#define USERD_WEB_PORT						"6322"
 		#define USERD_US_PORT						"-1"
-		#define DB_DIRECTORY						"C:\\WINNT"
-		#define ORDERS_DB_FILE_NAME					"C:\\WINNT\\explorer.exe"
-		#define USERS_DB_FILE_NAME					"C:\\WINNT\\explorer.exe"
-		#define UPDATE_FILE_NAME					"C:\\WINNT\\explorer.exe"
-		#define UPDATE_DIRECTORY					"C:\\WINNT\\"
-		#define LOG_DIRECTORY						"C:\\WINNT\\"
+		#define DB_DIRECTORY		"/usr/local/share/mythserver/db/"
+		#define ORDERS_DB_FILE_NAME	"orders.dat"
+		#define USERS_DB_FILE_NAME	"users.dat"
+		#define UPDATE_FILE_NAME	"update.dat"
+		#define UPDATE_DIRECTORY	"/usr/local/share/mythserver/update/"
+		#define LOG_DIRECTORY		"/usr/local/share/mythserver/log/"
 		#define ROOMS_LIST_FILE						"rooms.lst"
 		#define DEFAULT_APPLE_DOUBLE_DIRECTORY		".AppleDouble"
-		#define RESOURCE_DIRECTORY					"System Folder"
-		#define PC_APP_NAME							"Myth2.exe"
+		#define RESOURCE_DIRECTORY	"System Folder"
+		#define PC_APP_NAME		"Myth2.exe"
 		#define PC_NET_ONLY_APP_NAME				"obsolete"
-		#define PC_UPDATE_APP_NAME					"obsolete.exe"
+		#define PC_UPDATE_APP_NAME				"obsolete.exe"
 		#define PC_NET_ONLY_UPDATE_APP_NAME			"obsolete"
-		#define MAC_APP_NAME						"obsolete"
+		#define MAC_APP_NAME					"obsolete"
 		#define MAC_NET_ONLY_APP_NAME				"obsolete"
-		#define MAC_UPDATE_APP_NAME					"obsolete"
+		#define MAC_UPDATE_APP_NAME				"obsolete"
 		#define MAC_NET_ONLY_UPDATE_APP_NAME		"obsolete"
 		#define PATCH_FILE_NAME						"obsolete"
 		#define ADMIN_LOG_FILE_NAME					"adminlog.txt"
 		#define UPDATE_SERVER_STATS_FILE_PATH		"./"
 	#elif defined(BN2_DEMOVERSION)
 		#define BUNGIE_NET_ADMINISTRATOR			"nobody"
-		#define METASERVER_ROOT_DIR					"C:\\WINNT"
+		#define METASERVER_ROOT_DIR		"/usr/local/share/mythserver"
 		#define MOTD_FILE_NAME						"motd"
 		#define UPGRADE_PORT						"-1" // obsolete
 		#ifndef USERD_HOST
@@ -60,44 +60,44 @@
 		#define USERD_ROOM_PORT						"6333"
 		#define USERD_WEB_PORT						"6332"
 		#define USERD_US_PORT						"6334"
-		#define DB_DIRECTORY						"C:\\WINNT"
-		#define ORDERS_DB_FILE_NAME					"C:\\WINNT\\explorer.exe"
-		#define USERS_DB_FILE_NAME					"C:\\WINNT\\explorer.exe"
-		#define UPDATE_FILE_NAME					"C:\\WINNT\\explorer.exe"
-		#define UPDATE_DIRECTORY					"C:\\WINNT\\"
-		#define LOG_DIRECTORY						"C:\\WINNT\\"
+		#define DB_DIRECTORY	"/usr/local/share/mythserver/db"
+		#define ORDERS_DB_FILE_NAME "orders.dat"
+		#define USERS_DB_FILE_NAME "users.dat"
+		#define UPDATE_FILE_NAME  "update.dat"
+		#define UPDATE_DIRECTORY "/usr/local/share/mythserver/update/"
+		#define LOG_DIRECTORY	"/usr/local/share/mythserver/log/"
 		#define ROOMS_LIST_FILE						"rooms.lst"
 		#define DEFAULT_APPLE_DOUBLE_DIRECTORY		".AppleDouble"
-		#define RESOURCE_DIRECTORY					"System Folder"
-		#define PC_APP_NAME							"Myth2.exe"
-		#define PC_NET_ONLY_APP_NAME				"obsolete"
-		#define PC_UPDATE_APP_NAME					"obsolete.exe"
-		#define PC_NET_ONLY_UPDATE_APP_NAME			"obsolete"
-		#define MAC_APP_NAME						"obsolete"
-		#define MAC_NET_ONLY_APP_NAME				"obsolete"
-		#define MAC_UPDATE_APP_NAME					"obsolete"
+		#define RESOURCE_DIRECTORY			"System Folder"
+		#define PC_APP_NAME				"Myth2.exe"
+		#define PC_NET_ONLY_APP_NAME			"obsolete"
+		#define PC_UPDATE_APP_NAME			"obsolete.exe"
+		#define PC_NET_ONLY_UPDATE_APP_NAME		"obsolete"
+		#define MAC_APP_NAME				"obsolete"
+		#define MAC_NET_ONLY_APP_NAME			"obsolete"
+		#define MAC_UPDATE_APP_NAME			"obsolete"
 		#define MAC_NET_ONLY_UPDATE_APP_NAME		"obsolete"
-		#define PATCH_FILE_NAME						"obsolete"
-		#define ADMIN_LOG_FILE_NAME					"adminlog.txt"
+		#define PATCH_FILE_NAME				"obsolete"
+		#define ADMIN_LOG_FILE_NAME			"adminlog.txt"
 		#define UPDATE_SERVER_STATS_FILE_PATH		"./"
 	#endif
 	
 	#define get_bungie_net_administrator()			BUNGIE_NET_ADMINISTRATOR
-	#define get_metaserver_root_dir()				METASERVER_ROOT_DIR
-	#define get_motd_file_name()					MOTD_FILE_NAME
-	#define get_upgrade_port()						UPGRADE_PORT
-	#define get_userd_host()						USERD_HOST
-	#define get_userd_port()						USERD_PORT
-	#define get_userd_room_port()					USERD_ROOM_PORT
-	#define get_userd_web_port()					USERD_WEB_PORT
-	#define get_userd_us_port()						USERD_US_PORT
-	#define get_db_directory()						DB_DIRECTORY
-	#define get_orders_db_file_name()				ORDERS_DB_FILE_NAME
-	#define get_users_db_file_name()				USERS_DB_FILE_NAME
-	#define get_update_file_name()					UPDATE_FILE_NAME
-	#define get_update_directory()					UPDATE_DIRECTORY
-	#define get_log_directory()						LOG_DIRECTORY
-	#define get_rooms_list_file()					ROOMS_LIST_FILE
+	#define get_metaserver_root_dir()			METASERVER_ROOT_DIR
+	#define get_motd_file_name()				MOTD_FILE_NAME
+	#define get_upgrade_port()				UPGRADE_PORT
+	#define get_userd_host()				USERD_HOST
+	#define get_userd_port()				USERD_PORT
+	#define get_userd_room_port()				USERD_ROOM_PORT
+	#define get_userd_web_port()				USERD_WEB_PORT
+	#define get_userd_us_port()				USERD_US_PORT
+	#define get_db_directory()				DB_DIRECTORY
+	#define get_orders_db_file_name()			ORDERS_DB_FILE_NAME
+	#define get_users_db_file_name()			USERS_DB_FILE_NAME
+	#define get_update_file_name()				UPDATE_FILE_NAME
+	#define get_update_directory()				UPDATE_DIRECTORY
+	#define get_log_directory()				LOG_DIRECTORY
+	#define get_rooms_list_file()				ROOMS_LIST_FILE
 	#define get_default_apple_double_directory()	DEFAULT_APPLE_DOUBLE_DIRECTORY
 	#define get_resource_directory()				RESOURCE_DIRECTORY
 	#define get_pc_app_name()						PC_APP_NAME
