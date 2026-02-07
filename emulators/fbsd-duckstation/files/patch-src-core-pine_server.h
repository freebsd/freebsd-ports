Add missing type declarations (u8/u16/u32)

--- src/core/pine_server.h.orig	2024-06-14 05:59:32 UTC
+++ src/core/pine_server.h
@@ -5,6 +5,7 @@
  * here: https://code.govanify.com/govanify/pine/ */
 
 #pragma once
+#include "common/types.h"
 
 namespace PINEServer {
 bool IsRunning();
