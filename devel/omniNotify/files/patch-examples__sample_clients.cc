--- ./examples/sample_clients.cc.orig	2003-10-23 06:39:11.000000000 +0200
+++ ./examples/sample_clients.cc	2013-09-12 19:39:25.344066196 +0200
@@ -7,9 +7,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <fstream.h>
-#include <iostream.h>
-#include <iomanip.h>
+#include <fstream>
+#include <iostream>
+#include <iomanip>
+
+using namespace std;
 
 #ifdef HAVE_UNISTD_H
 #  include <unistd.h>
