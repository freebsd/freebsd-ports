--- lib/imlib/imconv.c.orig	Thu Oct  3 18:35:30 2002
+++ lib/imlib/imconv.c	Tue Jun  3 01:34:56 2003
@@ -591,6 +591,9 @@
 	}
     }
     IMFinishRequest(conn, offset);
+#ifdef STATUS_SYNC
+    IMFlush(conn);
+#endif /* STATUS_SYNC */
 }
 
 /*- preeditCaret: do actual preedit caret -*/
