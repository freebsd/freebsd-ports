--- vars.c.orig	2004-01-22 13:31:04 UTC
+++ vars.c
@@ -32,11 +32,9 @@
 #include <malloc.h>
 #endif
 
-extern void warnFor(Token*, char*, char*);
-
 void checkName(Token *cmd, int dynm)
 {
-    static char *badNames[] =
+    static const char *badNames[] =
     {
 	".",
 	"after",
@@ -158,7 +156,8 @@ void checkName(Token *cmd, int dynm)
 	"wm",
         (char *) 0
     };
-    char **bnp = badNames, msgb[256];
+    const char **bnp = badNames;
+    char msgb[256];
 
     if (cmd != noToken)
     {
@@ -198,7 +197,7 @@ void checkName(Token *cmd, int dynm)
     }
 }
 
-static VarData *newVar(char *name, enum VarType type)
+static VarData *newVar(const char *name, enum VarType type)
 {
     VarData *blp = (VarData *) malloc(sizeof(VarData));
 
@@ -211,7 +210,7 @@ static VarData *newVar(char *name, enum VarType type)
     return blp;
 }
 
-static VarData *addVar(char *name, enum VarType type, int array)
+static VarData *addVar(const char *name, enum VarType type, int array)
 {
     VarData *vp = newVar(name, type);
 
@@ -220,7 +219,7 @@ static VarData *addVar(char *name, enum VarType type, 
     return vp;
 }
 
-VarData *varKnown(char *name)
+VarData *varKnown(const char *name)
 {
     List *blp = blocks;
     List *lp;
@@ -245,7 +244,7 @@ VarData *varKnown(char *name)
     return (VarData *) 0;
 }
 
-VarData *declareVar(Token *nm, enum VarType type, int array)
+VarData *declareVar(const Token *nm, enum VarType type, int array)
 {
     VarData *vp = varKnown(nm->text);
     
@@ -268,7 +267,7 @@ VarData *declareVar(Token *nm, enum VarType type, int 
     return addVar(nm->text, type, array);
 }
 
-VarData *useVar(Token *nm, enum VarType type, int array)
+VarData *useVar(const Token *nm, enum VarType type, int array)
 {
     VarData *vp;
     
@@ -298,7 +297,7 @@ VarData *useVar(Token *nm, enum VarType type, int arra
     return vp;
 }
 
-VarData *setVar(Token *nm, enum VarType type, int array)
+VarData *setVar(const Token *nm, enum VarType type, int array)
 {
     VarData *vp;
 
