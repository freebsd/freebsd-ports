--- ./dialog.h.orig	2001-07-20 17:08:10.000000000 +0200
+++ ./dialog.h	2013-12-28 11:39:16.000000000 +0100
@@ -92,7 +92,7 @@
 		va_list ap;
 
 		va_start(ap, fmt);
-		vsprintf(errbuf, fmt, ap);
+		vsnprintf(errbuf, sizeof(errbuf), fmt, ap);
 		va_end(ap);
 		errstr = errbuf;
         }
@@ -878,7 +878,7 @@
 		if ( entry->text ) {
 			Fontserv->FreeText(entry->text);
 		}
-		sprintf(buf, "%d", *entry->variable);
+		snprintf(buf, sizeof(buf), "%d", *entry->variable);
 
 		if ( entry->hilite ) {
 			clear = Fg;
