--- src/network-libxml.c.orig	Thu Aug 12 09:48:05 2004
+++ src/network-libxml.c	Thu Aug 12 09:48:15 2004
@@ -72,7 +72,7 @@
 		g_set_error(err, NET_ERROR, NET_ERROR_PROTOCOL,
 				_("File not found."));
 		goto out;
-	default:
+	default:;
 	}
 
 	response = g_string_new(NULL);
