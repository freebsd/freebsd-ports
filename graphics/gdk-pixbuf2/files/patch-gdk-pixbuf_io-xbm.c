From 4f0f465f991cd454d03189497f923eb40c170c22 Mon Sep 17 00:00:00 2001
From: Matthias Clasen <mclasen@redhat.com>
Date: Sat, 14 Apr 2012 18:21:09 +0000
Subject: Avoid an integer overflow in the xbm loader

At the same time, reject some silly input, such as negative
width or height.

https://bugzilla.gnome.org/show_bug.cgi?id=672811
---
diff --git a/gdk-pixbuf/io-xbm.c b/gdk-pixbuf/io-xbm.c
index 46653b9..4f3e1e8 100644
--- gdk-pixbuf/io-xbm.c
+++ gdk-pixbuf/io-xbm.c
@@ -183,10 +183,16 @@ read_bitmap_file_data (FILE    *fstream,
 				type++;
 			}
 
-			if (!strcmp ("width", type))
+			if (!strcmp ("width", type)) {
+                                if (value <= 0)
+                                        RETURN (FALSE);
 				ww = (unsigned int) value;
-			if (!strcmp ("height", type))
+                        }
+			if (!strcmp ("height", type)) {
+                                if (value <= 0)
+                                        RETURN (FALSE);
 				hh = (unsigned int) value;
+                        }
 			if (!strcmp ("hot", type)) {
 				if (type-- == name_and_type
 				    || type-- == name_and_type)
@@ -231,6 +237,8 @@ read_bitmap_file_data (FILE    *fstream,
 		bytes_per_line = (ww+7)/8 + padding;
 
 		size = bytes_per_line * hh;
+                if (size / bytes_per_line != hh) /* overflow */
+                        RETURN (FALSE);
 		bits = g_malloc (size);
 
 		if (version10p) {
--
cgit v0.9.0.2
