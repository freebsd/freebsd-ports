--- lib/IlmCtl/CtlExc.cpp.orig	2014-06-03 01:11:24 UTC
+++ lib/IlmCtl/CtlExc.cpp
@@ -53,9 +53,9 @@
 ///////////////////////////////////////////////////////////////////////////
 
 #include <CtlExc.h>
+#include <cstdlib>
 #include <stdarg.h>
 #include <stdio.h>
-#include <alloca.h>
 #include <string.h>
 
 namespace Ctl {
