Add missing type declarations (u8/u16/u32)

--- src/core/gdb_server.h.orig	2024-06-14 05:59:32 UTC
+++ src/core/gdb_server.h
@@ -2,6 +2,8 @@
 // SPDX-License-Identifier: (GPL-3.0 OR CC-BY-NC-ND-4.0)
 
 #pragma once
+#include "common/types.h"
+
 #include <string_view>
 
 namespace GDBServer {
