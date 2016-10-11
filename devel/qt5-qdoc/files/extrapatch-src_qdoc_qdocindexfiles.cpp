There is a bug [1] in the old gcc used on FreeBSD 9.3, which makes
qdoc segfault on sorting while generating its index sections.

As mentioned in [2] by Michael Hansen, we can circument this by using
qSort instead of std::sort on FreeBSD 9.x.


[1] https://gcc.gnu.org/bugzilla/show_bug.cgi?id=59391
[2] https://bugreports.qt.io/browse/QTBUG-43057

--- src/qdoc/qdocindexfiles.cpp.orig	2016-10-02 07:52:39 UTC
+++ src/qdoc/qdocindexfiles.cpp
@@ -1476,7 +1476,7 @@ void QDocIndexFiles::generateIndexSectio
             const Aggregate* inner = static_cast<const Aggregate*>(node);

             NodeList cnodes = inner->childNodes();
-            std::sort(cnodes.begin(), cnodes.end(), compareNodes);
+            qSort(cnodes.begin(), cnodes.end(), compareNodes);

             foreach (Node* child, cnodes) {
                 generateIndexSections(writer, child, generateInternalNodes);
