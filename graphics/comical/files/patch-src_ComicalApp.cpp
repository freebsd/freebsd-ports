Add missing header and adjust location of icons

--- src/ComicalApp.cpp.orig	2006-03-03 04:23:15 UTC
+++ src/ComicalApp.cpp
@@ -30,7 +30,8 @@
 #include <wx/log.h>
 
 #if !defined(__WXMAC__) && !defined(__WXCOCOA__) && !defined(__WXMSW__) && !defined(__WXPM__)
-#include "../Comical Icons/comical.xpm"
+#include <wx/icon.h>
+#include "../ComicalIcons/comical.xpm"
 #endif
 
 // Create a new application object.
