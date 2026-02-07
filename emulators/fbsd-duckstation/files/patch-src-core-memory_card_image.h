Add missing type declarations (u8/u16/u32)

--- src/core/memory_card_image.h.orig	2024-06-14 05:59:32 UTC
+++ src/core/memory_card_image.h
@@ -2,6 +2,7 @@
 // SPDX-License-Identifier: (GPL-3.0 OR CC-BY-NC-ND-4.0)
 
 #pragma once
+#include "common/types.h"
 
 #include <array>
 #include <string>
