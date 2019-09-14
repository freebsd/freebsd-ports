--- KasumiException.hxx.orig	2006-05-26 17:41:25 UTC
+++ KasumiException.hxx
@@ -30,6 +30,8 @@
 #include "config.h"
 #endif
 
+#include <string>
+
 using namespace std;
 
 enum _output {STDOUT, STDERR, ERR_DIALOG, WARNING_DIALOG};
