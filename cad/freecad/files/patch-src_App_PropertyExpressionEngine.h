--- src/App/PropertyExpressionEngine.h.orig	2022-06-14 21:47:38 +0200
+++ src/App/PropertyExpressionEngine.h
@@ -179,7 +179,7 @@
     typedef boost::adjacency_list< boost::listS, boost::vecS, boost::directedS > DiGraph;
     typedef std::pair<int, int> Edge;
     // Note: use std::map instead of unordered_map to keep the binding order stable
-    #ifdef FC_OS_MACOSX
+    #if defined(FC_OS_MACOSX) ||  defined(FC_OS_BSD)
     typedef std::map<App::ObjectIdentifier, ExpressionInfo> ExpressionMap;
     #else
     typedef std::map<const App::ObjectIdentifier, ExpressionInfo> ExpressionMap;
