--- components/printers/unix/udlgselectprinter.pp	Wed Sep  5 11:24:20 2007
+++ components/printers/unix/udlgselectprinter.pp	Wed Sep  5 11:53:09 2007
@@ -132,7 +132,11 @@
   {$IFDEF darwin}
   miniCupsLibc,
   {$ELSE}
-  Libc,
+    {$IFDEF freebsd}
+    miniCupsLibc,
+    {$ELSE}
+     Libc,
+    {$ENDIF}
   {$ENDIF}
   uDlgPropertiesPrinter;
 
