--- lib/CModHandler.h.orig	2022-12-23 10:52:00 UTC
+++ lib/CModHandler.h
@@ -182,6 +182,8 @@ class DLL_LINKAGE CModInfo (public)
 
 	struct Version
 	{
+#undef major
+#undef minor
 		int major = 0;
 		int minor = 0;
 		int patch = 0;
