--- 3rdparty/libprojectm/MilkdropPresetFactory/Parser.cpp.orig	2018-12-05 17:16:34 UTC
+++ 3rdparty/libprojectm/MilkdropPresetFactory/Parser.cpp
@@ -1373,7 +1373,7 @@ PerFrameEqn * Parser::parse_implicit_per_frame_eqn(std
   PerFrameEqn * per_frame_eqn;
   GenExpr * gen_expr;
 
-  if (fs == NULL)
+  if (!fs)
     return NULL;
   if (param_string == NULL)
     return NULL;
@@ -1528,7 +1528,7 @@ InitCond * Parser::parse_per_frame_init_eqn(std::istre
 
   if (preset == NULL)
     return NULL;
-  if (fs == NULL)
+  if (!fs)
     return NULL;
 
   if ((token = parseToken(fs, name)) != tEq)
@@ -1842,7 +1842,7 @@ int Parser::parse_shapecode(char * token, std::istream
   /* Null argument checks */
   if (preset == NULL)
     return PROJECTM_FAILURE;
-  if (fs == NULL)
+  if (!fs)
     return PROJECTM_FAILURE;
   if (token == NULL)
     return PROJECTM_FAILURE;
@@ -2133,7 +2133,7 @@ int Parser::parse_wave(char * token, std::istream &  f
 
   if (token == NULL)
     return PROJECTM_FAILURE;
-  if (fs == NULL)
+  if (!fs)
     return PROJECTM_FAILURE;
   if (preset == NULL)
     return PROJECTM_FAILURE;
@@ -2315,7 +2315,7 @@ int Parser::parse_shape(char * token, std::istream &  
   if (token == NULL)
 
     return PROJECTM_FAILURE;
-  if (fs == NULL)
+  if (!fs)
     return PROJECTM_FAILURE;
   if (preset == NULL)
     return PROJECTM_FAILURE;
