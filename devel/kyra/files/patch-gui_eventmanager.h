--- gui/eventmanager.h.orig	2005-04-01 04:08:57 UTC
+++ gui/eventmanager.h
@@ -80,7 +80,7 @@ class KrEventManager
 		int keysym;
 		KrWidget* target;
 
-		bool operator==( const Accel& rhs )	{ return rhs.target == target; }
+		bool operator==( const Accel& rhs )	const { return rhs.target == target; }
 	};
 
 	KrEventManager();
