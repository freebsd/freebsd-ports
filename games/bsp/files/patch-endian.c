--- endian.c	Mon Jan 24 21:25:33 2005
+++ endian.c	Mon Jan 24 21:25:09 2005
@@ -195,7 +195,7 @@
 {
   Verbose("Doing endianness correction... ");
   ConvertVertex();
-  ConvertLineDef();
+  ConvertLinedef();
   ConvertSidedef();
   ConvertSector();
   ConvertPseg();
