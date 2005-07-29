Index: shell/source/proxysettings/soprxsettings.cxx
===================================================================
RCS file: /cvs/gsl/shell/source/proxysettings/Attic/soprxsettings.cxx,v
retrieving revision 1.4
diff -u -r1.4 soprxsettings.cxx
--- shell/source/proxysettings/soprxsettings.cxx	15 Aug 2002 13:26:49 -0000	1.4
+++ shell/source/proxysettings/soprxsettings.cxx	28 Jul 2005 22:03:30 -0000
@@ -87,9 +87,7 @@
 #include <osl/thread.h>
 #endif
 
-#ifndef MACOSX
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 #include <map>
 #include <utility>
 
