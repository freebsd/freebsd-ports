--- rplayd/spool.c.orig	1999-03-10 21:14:38 UTC
+++ rplayd/spool.c
@@ -1127,8 +1127,8 @@ spool_update()
 				spool_flow_pause(sp);
 			    }
 			}
-#endif /* HAVE_CDROM */
 		    }
+#endif /* HAVE_CDROM */
 		}
 		else
 		{
