--- src/importexport/musicxml/internal/musicxml/musicxmlsupport.cpp.orig	2024-02-05 22:18:41 UTC
+++ src/importexport/musicxml/internal/musicxml/musicxmlsupport.cpp
@@ -34,6 +34,8 @@
 
 #include "log.h"
 
+#include <QXmlStreamReader>
+
 using AccidentalType = mu::engraving::AccidentalType;
 using SymId = mu::engraving::SymId;
 const static QMap<QString, AccidentalType> smuflAccidentalTypes {
