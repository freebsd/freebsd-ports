--- ./libs/tex/io/exrinputfile.h.orig	2012-08-24 14:26:50.000000000 +0200
+++ ./libs/tex/io/exrinputfile.h	2013-10-29 13:16:03.000000000 +0100
@@ -48,10 +48,12 @@
 
 #include <aqsis/tex/io/itexinputfile.h>
 
+#include <OpenEXR/ImfInputFile.h>
+
 //------------------------------------------------------------------------------
-namespace Imf {
-	class InputFile;
-}
+//namespace Imf {
+//	class InputFile;
+//}
 
 namespace Aqsis {
 
