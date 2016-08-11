Index: lib/imlib/imconv.c
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/imlib/imconv.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
--- lib/imlib/imconv.c.orig	2002-10-03 09:35:30 UTC
+++ lib/imlib/imconv.c
@@ -591,6 +591,9 @@ OCCPreeditDrawArg *data;
 	}
     }
     IMFinishRequest(conn, offset);
+#ifdef STATUS_SYNC
+    IMFlush(conn);
+#endif /* STATUS_SYNC */
 }
 
 /*- preeditCaret: do actual preedit caret -*/
