--- src/outpane.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/outpane.cpp
@@ -115,7 +115,12 @@ void OutputList::GoToError()
           FXint begs[4]={0,0,0,0};
           FXint ends[4]={0,0,0,0};
           FXRex rx(pats[i].pat, REX_CAPTURE);
-          if (rx.match(txt,begs,ends,REX_FORWARD,3)) {
+#ifdef FOX_1_7_50_OR_NEWER
+          if (rx.search(txt,0,txt.length(),FXRex::Normal,begs,ends,3)>=0)
+#else
+          if (rx.match(txt,begs,ends,REX_FORWARD,3))
+#endif
+          {
             FXString filename = txt.mid(begs[1],ends[1]-begs[1]);
             FXString linenum =  txt.mid(begs[2],ends[2]-begs[2]);
             if (FXStat::isFile(filename)) {
@@ -228,7 +233,11 @@ void OutputList::SelectFirstError()
   FXRex rx(_(": [Ee]rror: "));
   for (FXint i=0; i<getNumItems(); i++) {
     FXListItem *item=getItem(i);
+#ifdef FOX_1_7_50_OR_NEWER
+    if (rx.search(item->getText(),0,item->getText().length())>=0) {
+#else
     if (rx.match(item->getText())) {
+#endif
       selectItem(i);
       setCurrentItem(i);
       makeItemVisible(i);
