--- src/Function_object.cpp.orig	Tue Nov 19 19:34:04 2002
+++ src/Function_object.cpp	Sun Sep 12 00:23:42 2004
@@ -436,9 +436,9 @@
 
    if (real_dp) {
 
-   if (value.type==MN_REAL) ss=true,v=value.R,img=QString("");
-   if (value.type==MN_COMPLEX) ss=false,v=value.R,img=QString("");
-   if (value.type==MN_VECTOR) ss=false,v=value.I,img=AppControl->Prefs->String("Vector_I");
+   if (value.type==MN_REAL) ss=true,v=value.mpl.m.R,img=QString("");
+   if (value.type==MN_COMPLEX) ss=false,v=value.mpl.m.R,img=QString("");
+   if (value.type==MN_VECTOR) ss=false,v=value.mpl.m.I,img=AppControl->Prefs->String("Vector_I");
 
    if (v<0) str=QString("-");
    else if (!first && may_have_plus) str=QString("+");
@@ -454,8 +454,8 @@
 
    if (complex_dp) {
 
-   if (value.type==MN_COMPLEX) ss=false,v=value.I,img=AppControl->Prefs->String("ImaginaryUnit");
-   if (value.type==MN_VECTOR) ss=false,v=value.J,img=AppControl->Prefs->String("Vector_J");
+   if (value.type==MN_COMPLEX) ss=false,v=value.mpl.m.I,img=AppControl->Prefs->String("ImaginaryUnit");
+   if (value.type==MN_VECTOR) ss=false,v=value.mpl.m.J,img=AppControl->Prefs->String("Vector_J");
 
    if (first && value.type==MN_COMPLEX) ss=true;
 
@@ -474,7 +474,7 @@
 
    if (vector_dp) {
 
-   if (value.type==MN_VECTOR) ss=false,v=value.K,img=AppControl->Prefs->String("Vector_K");
+   if (value.type==MN_VECTOR) ss=false,v=value.mpl.m.K,img=AppControl->Prefs->String("Vector_K");
 
    if (first) ss=true;
 
