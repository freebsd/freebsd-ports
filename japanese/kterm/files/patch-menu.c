--- menu.c.orig	2013-01-20 15:02:29.000000000 +0900
+++ menu.c	2013-01-20 15:02:56.000000000 +0900
@@ -843,6 +843,7 @@
     update_eucmode();
     update_sjismode();
     update_utf8mode();
+    make_unicode_map();
 }
 
 
@@ -867,6 +868,7 @@
 	update_eucmode();
 	update_sjismode();
 	update_utf8mode();
+	make_unicode_map();
     }
 }
 
@@ -891,6 +893,7 @@
 	update_eucmode();
 	update_sjismode();
 	update_utf8mode();
+	make_unicode_map();
     }
 }
 
