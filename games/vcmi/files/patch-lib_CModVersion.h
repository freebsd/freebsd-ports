--- lib/CModVersion.h.orig	2023-08-04 08:19:09 UTC
+++ lib/CModVersion.h
@@ -14,6 +14,8 @@ VCMI_LIB_NAMESPACE_BEGIN
 
 struct DLL_LINKAGE CModVersion
 {
+#undef major
+#undef minor
 	int major = 0;
 	int minor = 0;
 	int patch = 0;
