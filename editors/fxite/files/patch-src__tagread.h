--- src/tagread.h.orig	2013-10-03 09:22:51 UTC
+++ src/tagread.h
@@ -26,7 +26,7 @@ public:
 
 
 
-class AutoCompleter:public FXDict {
+class AutoCompleter:public Dictionary {
 private:
   void Show(SciDoc*sci);
   void Parse(char startchar, const char*filename);
