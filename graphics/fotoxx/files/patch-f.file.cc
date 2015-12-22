--- f.file.cc.orig	2015-05-01 09:40:38 UTC
+++ f.file.cc
@@ -74,6 +74,7 @@
 
 #define EX extern                                                          //  disable extern declarations
 #include "fotoxx.h"                                                        //  (variables in fotoxx.h are refs)
+#include <sys/wait.h>
 
 /**************************************************************************/
 
