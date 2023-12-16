--- he2/hebSegment.cxx.orig	2001-03-14 09:04:03 UTC
+++ he2/hebSegment.cxx
@@ -869,8 +869,8 @@ char *hebrew_segment_starters[] = { "\\R{", "\\section
 
 #define alpha "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
 #define anum "0123456789*+=-?@!%^&~:'\".,;()`<>/|_"
-#define alphanum alpha ## "0123456789*+=-?@!%^&~:'\".,;()`<>/|"
-#define all alphanum ## "${}^[]"
+#define alphanum alpha "0123456789*+=-?@!%^&~:'\".,;()`<>/|"
+#define all alphanum "${}^[]"
 int
 hebSegment::_processLatexCommand(char *buffer,  char **str, modeStack& stack)
 {
