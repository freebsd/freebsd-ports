--- engine/imnode.h.orig	2007-11-13 12:15:46.000000000 +0100
+++ engine/imnode.h	2007-11-13 12:18:19.000000000 +0100
@@ -288,7 +288,7 @@
 	/// Fetches the user defined data.
 	void* GetUserData()							{ return userData; }
 	/// Fetches the user defined data. Fetches the *same* user data as GetUserData, just uses a convenience cast.
-	U32   GetUserDataU32()						{ return (U32) userData; }
+	//U32   GetUserDataU32()						{ return (U32) userData; }
 
 	/** Return a copy if this object, not in a Tree(). It is
 		return untransformed. In the case of a sprite, the action
