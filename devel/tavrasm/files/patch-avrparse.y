--- src/avrparse.y.orig	Sat Dec  6 21:09:01 2003
+++ src/avrparse.y	Sat Dec  6 21:09:14 2003
@@ -46,7 +46,7 @@
 
 #include <string.h>
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "avrasm.hh"
 #include "symbol.hh"
 #include "semantic.hh"
