Add missing type declarations (u8/u16/u32)

--- src/duckstation-qt/graphicssettingswidget.h.orig	2025-05-07 13:16:56 UTC
+++ src/duckstation-qt/graphicssettingswidget.h
@@ -2,6 +2,7 @@
 // SPDX-License-Identifier: (GPL-3.0 OR CC-BY-NC-ND-4.0)
 
 #pragma once
+#include "common/types.h"
 
 #include <QtWidgets/QWidget>
 
