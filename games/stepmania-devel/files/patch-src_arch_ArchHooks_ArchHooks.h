--- src/arch/ArchHooks/ArchHooks.h.orig	2016-03-30 16:08:58 UTC
+++ src/arch/ArchHooks/ArchHooks.h
@@ -1,6 +1,8 @@
 #ifndef ARCH_HOOKS_H
 #define ARCH_HOOKS_H
 
+#include <ctime>
+
 struct lua_State;
 class ArchHooks
 {
