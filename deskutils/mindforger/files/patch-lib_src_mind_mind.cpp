--- lib/src/mind/mind.cpp.orig	2020-03-08 17:03:52 UTC
+++ lib/src/mind/mind.cpp
@@ -43,7 +43,7 @@ Mind::Mind(Configuration &configuration)
 #ifdef MF_MD_2_HTML_CMARK
       autolinking{new AutolinkingMind{*this}},
 #else
-      autolinking{nullptr}
+      autolinking{nullptr},
 #endif
       exclusiveMind{},
       timeScopeAspect{},
@@ -279,7 +279,7 @@ bool Mind::autolinkFindLongestPrefixWord(std::string& 
 {
 #ifdef MF_MD_2_HTML_CMARK
     return autolinking->findLongestPrefixWord(s, r);
-#elif
+#else
     return false;
 #endif
 }
@@ -1079,7 +1079,9 @@ void Mind::noteDemote(Note* note, Outline::Patch* patc
 
 void Mind::noteOnRename(const std::string& oldName, const std::string& newName)
 {
+#ifdef MF_MD_2_HTML_CMARK
     autolinking->update(oldName, newName);
+#endif
 }
 
 void Mind::onRemembering()
