--- ntext.cc.orig	2008-02-22 15:51:22 UTC
+++ ntext.cc
@@ -237,7 +237,7 @@ void NText::setBG(int c) {
 void NText::append(const char *text, int len, int color) {
   int i;
   NLine *nl;
-  char *p;
+  const char *p;
 
   if (len < 0) {
     discardExcess();
@@ -246,10 +246,8 @@ void NText::append(const char *text, int
 
   p = strchr(text, '\n');
   if (p!=NULL) {
-    *p = 0;
-    i = strlen(text);
-    nl = new NLine(text, color);
-    *p = '\n';
+    i = p - text;
+    nl = new NLine(text, color, i);
     lines.push_back(nl);
     formatLine(lines.size()-1);
     append(&p[1], len-(i+1), color);
