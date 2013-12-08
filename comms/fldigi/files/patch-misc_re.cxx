--- src/misc/re.cxx.orig	2013-11-17 19:25:55.932982749 -0500
+++ src/misc/re.cxx	2013-11-17 19:26:39.657979609 -0500
@@ -124,8 +124,8 @@
 
 size_t re_t::hash(void) const
 {
-	size_t h = tr1::hash<string>()(pattern);
-	return h ^ (tr1::hash<int>()(cflags) + 0x9e3779b9 + (h << 6) + (h >> 2));
+	size_t h = std::hash<string>()(pattern);
+	return h ^ (std::hash<int>()(cflags) + 0x9e3779b9 + (h << 6) + (h >> 2));
 }
 
 // ------------------------------------------------------------------------
