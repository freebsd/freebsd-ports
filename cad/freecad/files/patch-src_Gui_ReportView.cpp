--- ./src/Gui/ReportView.cpp.orig	Sat Feb 24 11:41:26 2007
+++ ./src/Gui/ReportView.cpp	Sun Apr 22 00:23:02 2007
@@ -241,7 +241,7 @@
 {
   QFont _font(  font() );
   _font.setFamily( "Courier" );
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
   _font.setPointSize( 15 );
 #else
   _font.setPointSize( 10 );
