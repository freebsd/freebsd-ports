--- tools/abisym.cc.orig	2021-03-07 00:17:35 UTC
+++ tools/abisym.cc
@@ -26,6 +26,7 @@
 /// in its symbol tables and report what it sees.
 
 #include <elf.h>
+#include <libgen.h>
 #include <cstring>
 #include <iostream>
 #include <sstream>
