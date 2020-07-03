--- BambooTracker/BambooTracker.pro.orig	2020-06-28 12:11:07 UTC
+++ BambooTracker/BambooTracker.pro
@@ -47,7 +47,7 @@ msvc {
 }
 else:if(gcc|clang) {
   # Pedantic settings, warning -> error escalation and C standard specification
-  CPPFLAGS += -Wall -Wextra -Werror -pedantic -pedantic-errors
+  CPPFLAGS += -Wall
   QMAKE_CFLAGS += -std=gnu11
 
   # Attempt to get the compiler version for version-specific handling
