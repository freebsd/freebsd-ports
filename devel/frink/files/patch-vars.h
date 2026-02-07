--- vars.h.orig	2003-02-27 10:33:04 UTC
+++ vars.h
@@ -11,7 +11,7 @@
  *
  */
 
-#ifndef FRINK_VARS_h
+#ifndef FRINK_VARS_H
 #define FRINK_VARS_H
 
 enum VarType
@@ -46,9 +46,9 @@ enum varCheck
 
 
 extern void checkName(Token *, int);
-extern VarData *varKnown(char *);
-extern VarData *declareVar(Token *, enum VarType, int);
-extern VarData *useVar(Token *, enum VarType, int);
-extern VarData *setVar(Token *, enum VarType, int);
+extern VarData *varKnown(const char *);
+extern VarData *declareVar(const Token *, enum VarType, int);
+extern VarData *useVar(const Token *, enum VarType, int);
+extern VarData *setVar(const Token *, enum VarType, int);
 
 #endif
