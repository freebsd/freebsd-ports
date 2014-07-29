--- ./he2/hebSegment.cxx.orig	Wed Mar 14 10:04:03 2001
+++ ./he2/hebSegment.cxx	Thu Jun 10 21:53:00 2004
@@ -869,8 +869,8 @@
 
 #define alpha "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
 #define anum "0123456789*+=-?@!%^&~:'\".,;()`<>/|_"
-#define alphanum alpha ## "0123456789*+=-?@!%^&~:'\".,;()`<>/|"
-#define all alphanum ## "${}^[]"
+#define alphanum alpha "0123456789*+=-?@!%^&~:'\".,;()`<>/|"
+#define all alphanum "${}^[]"
 int
 hebSegment::_processLatexCommand(char *buffer,  char **str, modeStack& stack)
 {
