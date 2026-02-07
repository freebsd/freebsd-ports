--- modules/javafx.web/src/main/native/Source/WebCore/css/StyleResolver.cpp.orig	2020-08-19 18:48:58 UTC
+++ modules/javafx.web/src/main/native/Source/WebCore/css/StyleResolver.cpp
@@ -211,7 +211,7 @@ StyleResolver::StyleResolver(Document& document)
     if (view)
         m_mediaQueryEvaluator = MediaQueryEvaluator { view->mediaType() };
     else
-        m_mediaQueryEvaluator = MediaQueryEvaluator { "all" };
+        m_mediaQueryEvaluator = MediaQueryEvaluator { };
 
     if (root) {
         m_rootDefaultStyle = styleForElement(*root, m_document.renderStyle(), nullptr, RuleMatchingBehavior::MatchOnlyUserAgentRules).renderStyle;
