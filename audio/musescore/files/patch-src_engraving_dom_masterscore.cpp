--- src/engraving/dom/masterscore.cpp.orig	2026-02-03 14:16:03 UTC
+++ src/engraving/dom/masterscore.cpp
@@ -79,6 +79,8 @@ MasterScore::MasterScore(const muse::modularity::Conte
     metaTags().insert({ u"platform", u"Apple Macintosh" });
 #elif defined(Q_OS_LINUX)
     metaTags().insert({ u"platform", u"Linux" });
+#elif defined(Q_OS_FREEBSD)
+    metaTags().insert({ u"platform", u"FreeBSD" });
 #else
     metaTags().insert({ u"platform", u"Unknown" });
 #endif
