--- src/searchpage.cpp.orig	2020-02-28 16:02:25 UTC
+++ src/searchpage.cpp
@@ -17,7 +17,7 @@ RET_SEARCH SearchPage::search(const Query& query)
     switch (query.method.direction) {
     case ExactWordSearch:
     case ForwardSearch:
-        queries << stemWords(query.query);
+/*        queries << stemWords(query.query);   */
         break;
     default:
         break;
