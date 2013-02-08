--- main.cpp.orig	1998-02-11 05:33:13.000000000 +0100
+++ main.cpp	2011-07-01 11:00:18.000000000 +0200
@@ -42,6 +42,7 @@
 
 //*****************************************************************************
 
+int
 main ( int argc, char **argv ) {
    QFont font("adobe", 12, QFont::Bold);
    QFont::setDefaultFont(font);
