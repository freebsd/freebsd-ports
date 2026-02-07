--- src/pms.cpp.orig	2010-05-13 23:17:13 UTC
+++ src/pms.cpp
@@ -23,6 +23,10 @@
 
 #include "pms.h"
 
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#endif
+
 using namespace std;
 
 Pms *		pms;
