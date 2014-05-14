--- net/route_msg.c.orig	2014-04-26 19:28:21.000000000 -0300
+++ net/route_msg.c	2014-04-26 19:28:57.000000000 -0300
@@ -608,8 +608,12 @@
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
