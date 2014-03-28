--- lcl/interfaces/qt/qtprivate.pp	2014-03-25 21:10:58.000000000 -0500
+++ lcl/interfaces/qt/qtprivate.pp	2014-03-25 21:12:20.000000000 -0500
@@ -23,7 +23,7 @@
 
 // todo: check if build macros can handle this and define it
 // in package LCL instead (it's needed for several widgetsets)
-{$if (FPC_FULLVERSION>=20701)}
+{$if (FPC_FULLVERSION>=20701) OR (FPC_FULLVERSION=20603)}
 {$define HAS_INHERITED_INSERTITEM}
 {$endif}
 
