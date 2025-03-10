--- src/importexport/musicxml/internal/musicxml/musicxmlsupport.cpp.orig	2024-12-11 12:43:18 UTC
+++ src/importexport/musicxml/internal/musicxml/musicxmlsupport.cpp
@@ -36,6 +36,8 @@
 
 #include "log.h"
 
+#include <QXmlStreamReader>
+
 using AccidentalType = mu::engraving::AccidentalType;
 using SymId = mu::engraving::SymId;
 
