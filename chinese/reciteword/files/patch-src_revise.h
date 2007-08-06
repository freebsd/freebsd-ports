--- src/revise.h.orig	2003-07-01 17:57:45.000000000 +0800
+++ src/revise.h	2007-07-30 16:38:45.000000000 +0800
@@ -51,7 +51,7 @@
 
 	void init ();
 	void show ();
-	void create_plane (gint x, gint y);
+	void create_plane (glong x, glong y);
 	void close ();
 };
 
