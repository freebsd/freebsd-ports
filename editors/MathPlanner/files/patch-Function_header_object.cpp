--- src/Function_header_object.cpp.orig	Mon Sep  2 01:57:32 2002
+++ src/Function_header_object.cpp	Sun Sep 12 00:21:56 2004
@@ -229,7 +229,7 @@
 math_node function_defination_object::Calculate()
 {
 
-value.R=0;
+value.mpl.m.R=0;
 value.type=MN_REAL;
 
 return(value);
@@ -256,7 +256,7 @@
 AssignLo.Init(AppControl);
 
 math_node zero;
-zero.R=0; zero.type=MN_REAL;
+zero.mpl.m.R=0; zero.type=MN_REAL;
 
 pointer=false;
 
