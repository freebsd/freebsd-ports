--- src/aneditor.cxx.orig	Tue Nov  5 15:51:38 2002
+++ src/aneditor.cxx	Tue Nov  5 15:52:01 2002
@@ -289,6 +289,9 @@
 	void EvalOutputArrived(GList* lines, int textPos, const string &expression);
 };
 
+inline bool nonFuncChar(char ch) {
+    return strchr("\t\n\r !\"#%&'()*+,-./:;<=>?@[\\]^`{|}~", ch) != NULL;
+}
 
 class ExpressionEvaluationTipInfo
 // Utility class to help displaying expression values in tips.
