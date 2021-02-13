--- libr/debug/p/native/bsd/bsd_debug.c.orig	2021-02-13 20:27:22 UTC
+++ libr/debug/p/native/bsd/bsd_debug.c
@@ -488,7 +488,6 @@ RList *bsd_desc_list(int pid) {
 		case KF_TYPE_PIPE: type = 'p'; break;
 		case KF_TYPE_FIFO: type = 'f'; break;
 		case KF_TYPE_KQUEUE: type = 'k'; break;
-		case KF_TYPE_CRYPTO: type = 'c'; break;
 		case KF_TYPE_MQUEUE: type = 'm'; break;
 		case KF_TYPE_SHM: type = 'h'; break;
 		case KF_TYPE_PTS: type = 't'; break;
