--- tsl/src/reorder.c.orig	2021-01-12 02:00:38 UTC
+++ tsl/src/reorder.c
@@ -794,6 +794,7 @@ copy_heap_data(Oid OIDNewHeap, Oid OIDOldHeap, Oid OID
 			case HEAPTUPLE_RECENTLY_DEAD:
 				tups_recently_dead += 1;
 				/* fall through */
+				__attribute__((fallthrough));
 			case HEAPTUPLE_LIVE:
 				/* Live or recently dead, must copy it */
 				isdead = false;
