--- ./src/Gui/PythonConsole.cpp.orig	Sat Feb 24 11:41:26 2007
+++ ./src/Gui/PythonConsole.cpp	Sun Apr 22 00:21:56 2007
@@ -75,7 +75,7 @@
   hPrefGrp->Attach( this );
 
   zoomIn(2);
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
   QFont serifFont( "Courier", 15, QFont::Normal );
 #else
   QFont serifFont( "Courier", 10, QFont::Normal );
@@ -182,7 +182,7 @@
   font.setBold( false ); // if current font is bold we must reset it first
   if (strcmp(sReason, "FontSize") == 0)
   {
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
     QString txt = hPrefGrp->GetASCII( "FontSize", "15" ).c_str();
 #else
     QString txt = hPrefGrp->GetASCII( "FontSize", "10" ).c_str();
@@ -190,7 +190,7 @@
 
     bool ok;
     int size = txt.toInt(&ok);
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
     if ( !ok ) size = 15; 
 #else
     if ( !ok ) size = 10; 
