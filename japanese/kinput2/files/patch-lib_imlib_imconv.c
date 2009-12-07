Index: lib/imlib/imconv.c
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/imlib/imconv.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- lib/imlib/imconv.c	7 Dec 2009 06:36:04 -0000	1.1.1.1
+++ lib/imlib/imconv.c	7 Dec 2009 06:44:58 -0000	1.2
@@ -591,6 +591,9 @@ OCCPreeditDrawArg *data;
 	}
     }
     IMFinishRequest(conn, offset);
+#ifdef STATUS_SYNC
+    IMFlush(conn);
+#endif /* STATUS_SYNC */
 }
 
 /*- preeditCaret: do actual preedit caret -*/
