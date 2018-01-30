--- interfaces/qt/qt45.pas.orig	2014-02-05 12:08:29 UTC
+++ interfaces/qt/qt45.pas
@@ -45,7 +45,7 @@ const
 {$ENDIF}
 
 {$IFNDEF QTOPIA}
-  {$IF DEFINED(LINUX) or DEFINED(FREEBSD) or DEFINED(NETBSD)}
+  {$IF DEFINED(LINUX) or DEFINED(FREEBSD) or DEFINED(NETBSD) or DEFINED(DRAGONFLY)}
     {$DEFINE BINUX}
     Qt4PasLib = 'libQt4Pas.so.5';
   {$ENDIF}
