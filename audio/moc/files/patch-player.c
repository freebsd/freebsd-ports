Index: player.c
===================================================================
--- player.c	(revision 1478)
+++ player.c	(working copy)
@@ -615,7 +615,9 @@
 		}
 
 		already_decoded_time = precache.decoded_time;
-		bitrate_list = precache.bitrate_list;
+		bitrate_list_init (&bitrate_list);
+		bitrate_list.head = precache.bitrate_list.head;
+		bitrate_list.tail = precache.bitrate_list.tail;
 
 		/* don't free list elements when reseting precache */
 		precache.bitrate_list.head = NULL;
