--- src/hugin/ImagesPanel.cpp.orig	Thu Aug 11 20:18:49 2005
+++ src/hugin/ImagesPanel.cpp	Thu Aug 11 20:20:24 2005
@@ -448,9 +448,9 @@
         for (UIntSet::const_iterator it = selImg.begin();
              it != selImg.end(); ++it )
         {
-            vars[i].insert(make_pair("y", Variable("y",0.0)));
-            vars[i].insert(make_pair("p", Variable("p",0.0)));
-            vars[i].insert(make_pair("r", Variable("r",0.0)));
+            vars[i].insert(make_pair((char *) "y", Variable("y",0.0)));
+            vars[i].insert(make_pair((char *) "p", Variable("p",0.0)));
+            vars[i].insert(make_pair((char *) "r", Variable("r",0.0)));
             i++;
         }
         GlobalCmdHist::getInstance().addCommand(
