--- src/scintillaeditor.h.orig	2015-03-05 20:25:13 UTC
+++ src/scintillaeditor.h
@@ -11,9 +11,11 @@
 #include "scadlexer.h"
 #include "parsersettings.h"
 
+#ifndef Q_MOC_RUN
 #include <boost/shared_ptr.hpp>
 #include <boost/property_tree/ptree.hpp>
 #include <boost/property_tree/json_parser.hpp>
+#endif
 
 class EditorColorScheme
 {
