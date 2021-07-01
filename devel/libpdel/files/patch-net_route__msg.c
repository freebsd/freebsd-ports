--- net/route_msg.c.orig	2009-05-13 21:36:04 UTC
+++ net/route_msg.c
@@ -575,8 +575,12 @@ route_msg_print(struct route_msg *msg, FILE *fp)
 	case RTM_REDIRECT:	typestr = "REDIRECT"; break;
 	case RTM_MISS:		typestr = "MISS"; break;
 	case RTM_LOCK:		typestr = "LOCK"; break;
+#ifdef RTM_OLDADD
 	case RTM_OLDADD:	typestr = "OLDADD"; break;
+#endif
+#ifdef RTM_OLDDEL
 	case RTM_OLDDEL:	typestr = "OLDDEL"; break;
+#endif
 	case RTM_RESOLVE:	typestr = "RESOLVE"; break;
 	case RTM_NEWADDR:	typestr = "NEWADDR"; break;
 	case RTM_DELADDR:	typestr = "DELADDR"; break;
