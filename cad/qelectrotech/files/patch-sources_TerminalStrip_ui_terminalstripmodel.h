--- sources/TerminalStrip/ui/terminalstripmodel.h.orig	2026-01-28 12:19:13 UTC
+++ sources/TerminalStrip/ui/terminalstripmodel.h
@@ -29,8 +29,8 @@
 #include "modelTerminalData.h"
 
 //Code to use QColor as key for QHash
-inline uint qHash(const QColor &key, uint seed) {
-	return qHash(key.name(), seed);
+inline size_t qHash(const QColor &key, size_t seed = 0) {
+	return qHash(key.rgba(), seed);
 }
 
 //needed to use QPointer<Element> as key of QHash
