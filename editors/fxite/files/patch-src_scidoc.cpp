--- src/scidoc.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/scidoc.cpp
@@ -620,7 +620,11 @@ bool SciDoc::SetLanguageForHeader(const FXString &fn)
     } else {
       // Take a wild guess - if the file contains the word "class" it's probably  C++
       const char *content=(const char*)(sendMessage(SCI_GETCHARACTERPOINTER,0,0));
+#ifdef FOX_1_7_50_OR_NEWER
+      if (FXRex("\\<class\\>").search(content,strlen(content),0,strlen(content))>=0) {
+#else
       if (FXRex("\\<class\\>").match(content)) {
+#endif
         setLanguage("cpp");
       } else {
         setLanguage("c");
