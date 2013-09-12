--- ./examples/sample_functions.cc.orig	2003-10-23 06:39:11.000000000 +0200
+++ ./examples/sample_functions.cc	2013-09-12 19:41:47.835066655 +0200
@@ -2,10 +2,12 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 #include "sample_functions.h"
 
+using namespace std;
+
 ///////////////////////////////////////////////////////////////////
 //             USER-DEFINED FUNCTION EXAMPLES                    //
 ///////////////////////////////////////////////////////////////////
