--- src/arch/ArchHooks/ArchHooks.h.orig
+++ src/arch/ArchHooks/ArchHooks.h
@@ -1,6 +1,8 @@
 #ifndef ARCH_HOOKS_H
 #define ARCH_HOOKS_H
 
+#include <ctime>
+
 struct lua_State;
 class ArchHooks
 {
