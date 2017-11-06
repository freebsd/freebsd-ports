--- pugl/pugl/pugl_x11.c.orig	2017-08-07 03:15:15 UTC
+++ pugl/pugl/pugl_x11.c
@@ -648,7 +648,7 @@ puglPasteFromClipboard(PuglView* view, s
 		if(  (xevent.xselection.selection == impl->clipboard)
 			&& (xevent.xselection.target == impl->utf8_string)
 			&& (xevent.xselection.property == XA_PRIMARY) ) {
-			ulong nitems, rem;
+			uint32_t nitems, rem;
 			int format;
 			uint8_t* data;
 			Atom type;
