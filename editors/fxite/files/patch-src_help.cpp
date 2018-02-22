--- src/help.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/help.cpp
@@ -36,7 +36,13 @@
 #define sendString(iMessage, wParam, lParam) sendMessage(iMessage, wParam, reinterpret_cast<long>(lParam))
 
 
+#ifdef FOX_1_7_50_OR_NEWER
+# define RxFind(rx,subj,start,beg,end,npar) (rx.search(subj,strlen(subj),start,strlen(subj),FXRex::Normal,beg,end,npar)>=0)
+#else
+# define RxFind(rx,subj,start,beg,end,npar) (rx.match(subj,beg,end,REX_FORWARD,npar,start))
+#endif
 
+
 enum {
   SCHLP_FIXED,
   SCHLP_ITALIC,
@@ -224,7 +230,7 @@ void SciHelp::replace(const char*oldstr, const char*ne
   FXRex generic_rx(oldstr, REX_NORMAL|REX_NEWLINE);
   content=(const char*)(sendMessage(SCI_GETCHARACTERPOINTER,0,0));
   FXint n=strlen(newstr);
-  while (generic_rx.match(content,beg,end,REX_FORWARD,1)) {
+  while (RxFind(generic_rx,content,0,beg,end,1)) {
     sendMessage(SCI_SETTARGETSTART,beg[0],0);
     sendMessage(SCI_SETTARGETEND,end[0],0);
     sendString(SCI_REPLACETARGET,n,newstr);
@@ -261,7 +267,7 @@ void SciHelp::parse(const char*txt, unsigned int size)
   for (FXint i=SCHLP_FIRST; i<SCHLP_LAST; i++) {
     content=(const char*)(sendMessage(SCI_GETCHARACTERPOINTER,0,0));
     FXRex rx(phrases[i], REX_CAPTURE|REX_NEWLINE);
-    while (rx.match(content,beg,end,REX_FORWARD,2)) {
+    while (RxFind(rx,content,0,beg,end,2)) {
       sendMessage(SCI_SETTARGETSTART,beg[0],0);
       sendMessage(SCI_SETTARGETEND,end[0],0);
       char*tmp=my_strndup(content+beg[1], end[1]-beg[1]);
@@ -289,10 +295,10 @@ void SciHelp::parse(const char*txt, unsigned int size)
   }
 
   // Make the editor's name stand out a little...
-  FXRex appname_rx("\\<"APP_NAME"\\>", REX_NORMAL|REX_NEWLINE);
+  FXRex appname_rx("\\<" APP_NAME "\\>", REX_NORMAL|REX_NEWLINE);
   content=(const char*)(sendMessage(SCI_GETCHARACTERPOINTER,0,0));
   FXint p=0;
-  while (appname_rx.match(content,beg,end,REX_FORWARD,1, p)) {
+  while (RxFind(appname_rx,content,p,beg,end,1)) {
     sendMessage(SCI_STARTSTYLING,beg[0],0xff);
     sendMessage(SCI_SETSTYLING,(end[0]-beg[0]),SCHLP_LOGO);
     p=end[0];
