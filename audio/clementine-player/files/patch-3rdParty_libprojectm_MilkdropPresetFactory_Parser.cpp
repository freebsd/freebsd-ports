--- 3rdparty/libprojectm/MilkdropPresetFactory/Parser.cpp.orig	2018-01-31 22:06:57.261592000 +0000
+++ 3rdparty/libprojectm/MilkdropPresetFactory/Parser.cpp	2018-01-31 22:07:38.081299000 +0000
@@ -1373,7 +1373,7 @@
   PerFrameEqn * per_frame_eqn;
   GenExpr * gen_expr;
 
-  if (fs == NULL)
+  if (!fs)
     return NULL;
   if (param_string == NULL)
     return NULL;
@@ -1528,7 +1528,7 @@
 
   if (preset == NULL)
     return NULL;
-  if (fs == NULL)
+  if (!fs)
     return NULL;
 
   if ((token = parseToken(fs, name)) != tEq)
@@ -1842,7 +1842,7 @@
   /* Null argument checks */
   if (preset == NULL)
     return PROJECTM_FAILURE;
-  if (fs == NULL)
+  if (!fs)
     return PROJECTM_FAILURE;
   if (token == NULL)
     return PROJECTM_FAILURE;
@@ -2133,7 +2133,7 @@
 
   if (token == NULL)
     return PROJECTM_FAILURE;
-  if (fs == NULL)
+  if (!fs)
     return PROJECTM_FAILURE;
   if (preset == NULL)
     return PROJECTM_FAILURE;
@@ -2315,7 +2315,7 @@
   if (token == NULL)
 
     return PROJECTM_FAILURE;
-  if (fs == NULL)
+  if (!fs)
     return PROJECTM_FAILURE;
   if (preset == NULL)
     return PROJECTM_FAILURE;
