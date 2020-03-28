--- utils/HtmlOutputDev.cc.orig	2020-03-01 19:52:52 UTC
+++ utils/HtmlOutputDev.cc
@@ -1838,7 +1838,7 @@ int HtmlOutputDev::getOutlinePageNum(OutlineItem *item
     if (!action || action->getKind() != actionGoTo)
         return pagenum;
 
-    link = dynamic_cast<const LinkGoTo*>(action);
+    link = static_cast<const LinkGoTo*>(action);
 
     if (!link || !link->isOk())
         return pagenum;
