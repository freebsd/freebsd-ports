--- src/pcscdaemon.c.orig	Mon Jan 22 16:31:21 2007
+++ src/pcscdaemon.c	Mon Jan 22 16:33:52 2007
@@ -199,6 +199,14 @@
 		switch (rsp = SHMProcessEventsServer(&dwClientID, 0))
 		{
 
+		case 2:
+			/*						/*
+			 * timeout in SHMProcessEventsServer(): do nothing
+			 * this is used to catch the Ctrl-C signal at some time when
+			 * nothing else happens
+			 */
+			break;
+
 		case 0:
 			Log2(PCSC_LOG_DEBUG, "A new context thread creation is requested: %d", dwClientID);
 			rv = CreateContextThread(&dwClientID);
