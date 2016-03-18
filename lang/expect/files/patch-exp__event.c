--- exp_event.c.orig	2010-07-01 00:53:49 UTC
+++ exp_event.c
@@ -120,6 +120,8 @@ exp_unblock_background_channelhandler(es
 	case disarm_req_while_blocked:
 	    exp_disarm_background_channelhandler_force(esPtr);
 	    break;
+	default:
+	    break;
     }
 }
 
