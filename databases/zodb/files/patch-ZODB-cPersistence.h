--- ZODB/cPersistence.h.orig	Wed Sep 13 03:32:31 2000
+++ ZODB/cPersistence.h	Tue Sep 18 14:56:53 2001
@@ -86,7 +86,7 @@
 #ifndef CPERSISTENCE_H
 #define CPERSISTENCE_H
 
-#include "ExtensionClass/ExtensionClass.h"
+#include "../ExtensionClass/src/ExtensionClass.h"
 #include <time.h>
 
 #define cPersistent_HEAD PyObject_HEAD PyObject *jar, *oid; char serial[8]; unsigned short atime;  signed char state;  unsigned char reserved; 
