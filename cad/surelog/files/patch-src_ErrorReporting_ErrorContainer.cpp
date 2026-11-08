-- Fix unit tests crashing when Python support is compiled in but not initialized.
-- ErrorContainer::createErrorMessage() was unconditionally calling PythonAPI::evalScript()
-- with a null interpreter pointer, causing a fatal Python GIL error.
-- Fall back to the built-in message formatting when the Python interpreter has
-- not been initialized (m_interpState is nullptr).
-- See https://github.com/chipsalliance/Surelog/issues/3971
--- src/ErrorReporting/ErrorContainer.cpp.orig	2026-09-16 05:28:55 UTC
+++ src/ErrorReporting/ErrorContainer.cpp
@@ -261,7 +261,8 @@ std::tuple<std::string, bool, bool> ErrorContainer::cr
         padding = "00";
       else if (msg.m_errorId < 1000)
         padding = "0";
-      if ((reentrantPython == false) || (!m_clp->pythonAllowed())) {
+      if ((reentrantPython == false) || (!m_clp->pythonAllowed()) ||
+          (m_interpState == nullptr)) {
         tmp = "[" + severity + ":" + category + padding +
               std::to_string(msg.m_errorId) + "] " + location + text + "\n";
       } else {
