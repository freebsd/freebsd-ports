--- widgets/disassemblerlistingview/disassemblercolumnview.cpp.orig	2020-05-21 11:13:41 UTC
+++ widgets/disassemblerlistingview/disassemblercolumnview.cpp
@@ -1,6 +1,7 @@
 #include "disassemblercolumnview.h"
 #include "../../themeprovider.h"
 #include <QPainter>
+#include <QPainterPath>
 
 DisassemblerColumnView::DisassemblerColumnView(QWidget *parent) : QWidget(parent), m_disassembler(nullptr), m_first(-1), m_last(-1)
 {
