--- kbarcode/zplutils.cpp.orig	Wed Nov  5 20:26:46 2003
+++ kbarcode/zplutils.cpp	Fri Dec 26 10:22:53 2003
@@ -307,7 +307,7 @@
     setField( "<ESC>E3<CAN>" );  // choose format number 3
 
     for( unsigned int i = 0; i < values.count(); i++ )
-        setField( values[i] + ( i != values.count() - 1 ? "<CR>" : QString::null ) );
+        setField( values[i] + ( i != values.count() - 1 ? QString("<CR>") : QString::null ) );
     
     // end actual data
     setField( "<ETB>" );
