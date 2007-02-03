--- src/gui/shoplistbox.cpp	Fri Jan 26 14:07:54 2007
+++ src/gui/shoplistbox.cpp	Fri Jan 26 14:03:21 2007
@@ -112,7 +112,7 @@
         mSelected = std::min(mListModel->getNumberOfElements() - 1,
                              std::max(-1, selected));
 
-        gcn::BasicContainer *parent = getParent();
+        gcn::Widget *parent = getParent();
         if (parent)
         {
             gcn::Rectangle scroll;

