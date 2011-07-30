--- src/toolbar.vala.orig	2011-06-24 14:42:58.000000000 +0200
+++ src/toolbar.vala	2011-06-24 14:43:11.000000000 +0200
@@ -343,7 +343,7 @@ namespace Abraca {
 
 			try {
 				var loader = new Gdk.PixbufLoader();
-				loader.write(data, data.length);
+				loader.write(data);
 				loader.close();
 
 				var pixbuf = loader.get_pixbuf();
