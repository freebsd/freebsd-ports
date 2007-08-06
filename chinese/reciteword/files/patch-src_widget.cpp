--- src/widget.cpp.orig	2005-10-06 15:32:10.000000000 +0800
+++ src/widget.cpp	2007-07-30 16:38:45.000000000 +0800
@@ -817,7 +817,7 @@
 	default:
 		return_val = TRUE;
 		if ((length < parent->max_length) && (event->keyval >= 0x20)
-		    && (event->keyval <= 0xFF))
+		    && (event->keyval <= 0x7E))
 		{
 			gchar key;
 			key = event->keyval;
