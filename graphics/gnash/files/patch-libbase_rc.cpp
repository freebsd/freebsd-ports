$NetBSD: patch-libbase_rc.cpp,v 1.1 2013/02/26 11:04:25 joerg Exp $

--- libbase/rc.cpp.orig	2013-02-25 18:40:46.000000000 +0000
+++ libbase/rc.cpp
@@ -83,7 +83,7 @@ RcInitFile::RcInitFile()
         DEFAULT_FLASH_REV_NUMBER ",0"),
     // An empty string leaves detection to VM.cpp:
     _flashSystemOS(""),
-    _flashSystemManufacturer("Gnash "DEFAULT_FLASH_SYSTEM_OS),
+    _flashSystemManufacturer("Gnash " DEFAULT_FLASH_SYSTEM_OS),
     _actionDump(false),
     _parserDump(false),
     _verboseASCodingErrors(false),
