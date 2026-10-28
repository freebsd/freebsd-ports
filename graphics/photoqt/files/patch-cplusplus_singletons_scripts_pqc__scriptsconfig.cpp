- Also accept PQMZXINGQT, otherwise QR/barcode detection is hidden from the context menu

--- cplusplus/singletons/scripts/pqc_scriptsconfig.cpp.orig	2026-07-30 17:47:41 UTC
+++ cplusplus/singletons/scripts/pqc_scriptsconfig.cpp
@@ -595,7 +595,7 @@ bool PQCScriptsConfig::isZXingSupportEnabled() {
 }
 
 bool PQCScriptsConfig::isZXingSupportEnabled() {
-#ifdef PQMZXING
+#if defined(PQMZXING) || defined(PQMZXINGQT)
     return true;
 #endif
     return false;
