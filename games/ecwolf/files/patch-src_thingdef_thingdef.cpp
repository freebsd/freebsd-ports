--- src/thingdef/thingdef.cpp.orig	2020-08-24 18:22:35 UTC
+++ src/thingdef/thingdef.cpp
@@ -283,7 +283,7 @@ static const struct ExpressionFunction
 	{ "random",		TypeHierarchy::INT,		2,	true,	ExprRandom },
 	{ "sin",		TypeHierarchy::FLOAT,	1,	false,	ExprSin },
 
-	{ NULL, 0, false, NULL }
+	{ NULL, 0, false, false }
 };
 
 ////////////////////////////////////////////////////////////////////////////////
