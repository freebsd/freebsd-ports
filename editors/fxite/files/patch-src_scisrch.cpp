--- src/scisrch.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/scisrch.cpp
@@ -29,6 +29,12 @@
 #define SciMsg(im,wp,lp) sci->sendMessage(im,wp,lp)
 #define SciStr(im,wp,lp) sci->sendString(im,wp,lp)
 
+#ifdef FOX_1_7_50_OR_NEWER
+# define RxMatch(rx, str, len, beg, end, mode, npar, fm, to) ( ((rx)->search((str), (len), (fm), (to), (mode), (beg), (end), (npar))) >=0 )
+#else
+# define RxMatch(rx, str, len, beg, end, mode, npar, fm, to) ( ((rx)->match ((str), (len), (beg), (end), (mode), (npar), (fm), (to))) !=0 )
+#endif
+
 #if 1
 
 // The capitalization of text inserted by `&' or `\1', `\2', ... `\9' can be altered by
@@ -222,7 +228,7 @@ int SciSearch::FindTextNoSel(const FXString &what, FXu
   if (fm<0) { fm=0; }
   if (to>len) { to=len; }
   FXuint dirn=isfwd?REX_FORWARD:REX_BACKWARD;
-  if (rx.match(content,len,begs,ends,dirn,MAX_CAPTURES,fm,to)) {
+  if (RxMatch(&rx,content,len,begs,ends,dirn,MAX_CAPTURES,fm,to)) {
     beg=isfwd?begs[0]:ends[0];
     end=isfwd?ends[0]:begs[0];
     return 1;
@@ -256,8 +262,8 @@ bool SciSearch::FindText(const FXString &what, FXuint 
   long fm = isfwd? pos : 0;
   long to = isfwd? len : (pos-1);
   if (
-    rx.match(content,len,begs,ends,dirn,MAX_CAPTURES,fm,to) ||
-    (wrap && rx.match(content,len,begs,ends,dirn,MAX_CAPTURES,0,len))
+    RxMatch(&rx,content,len,begs,ends,dirn,MAX_CAPTURES,fm,to) ||
+    (wrap && RxMatch(&rx,content,len,begs,ends,dirn,MAX_CAPTURES,0,len))
   ) {
     SciMsg(SCI_SETTARGETSTART,begs[0],0);
     SciMsg(SCI_SETTARGETEND,ends[0],0);
@@ -383,8 +389,8 @@ long SciSearch::ReplaceAllInDoc(const FXString &search
   SciMsg(SCI_SETSEARCHFLAGS,0,0);
   SciMsg(SCI_BEGINUNDOACTION,0,0);
   while (1) {
-    if (end==start) { break; }
-    if (rx.match(content,end,begs,ends,srchflags,MAX_CAPTURES,start,end)) {
+    if (end<=start) { break; }
+    if (RxMatch(&rx,content,end,begs,ends,REX_FORWARD|REX_NOT_EMPTY,MAX_CAPTURES,start,end)) {
       SciMsg(SCI_SETTARGETSTART,begs[0],0);
       SciMsg(SCI_SETTARGETEND,ends[0],0);
       FXString newstr=DoSubstitute(content,begs,ends,repl_template,MAX_CAPTURES);
@@ -438,7 +444,7 @@ long SciSearch::ReplaceAllInSel(const FXString &search
 
     SciMsg(SCI_SETSEARCHFLAGS,0,0);
     if (bol_only) { // Special case, start of first line
-      if (rx.match(content,end,begs,ends,REX_FORWARD|REX_NOT_EMPTY,MAX_CAPTURES,start,end)) {
+      if (RxMatch(&rx,content,end,begs,ends,REX_FORWARD|REX_NOT_EMPTY,MAX_CAPTURES,start,end)) {
         SciMsg(SCI_SETTARGETSTART,begs[0],0);
         SciMsg(SCI_SETTARGETEND,ends[0],0);
         FXString newstr=DoSubstitute(content,begs,ends,repl_template,MAX_CAPTURES);
@@ -452,7 +458,7 @@ long SciSearch::ReplaceAllInSel(const FXString &search
     long substart=start;
     while (1) {
       if (end<=substart) { break; }
-      if (rx.match(content,end,begs,ends,srchflags,MAX_CAPTURES,substart,end)) {
+      if (RxMatch(&rx,content,end,begs,ends,srchflags,MAX_CAPTURES,substart,end)) {
         SciMsg(SCI_SETTARGETSTART,begs[0],0);
         SciMsg(SCI_SETTARGETEND,ends[0],0);
         FXString newstr=DoSubstitute(content,begs,ends,repl_template,MAX_CAPTURES);
