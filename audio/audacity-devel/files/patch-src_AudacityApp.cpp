--- src/AudacityApp.cpp.orig	2009-11-27 00:27:29.000000000 +0100
+++ src/AudacityApp.cpp	2009-11-27 00:48:36.000000000 +0100
@@ -23,6 +23,15 @@ It handles initialization and terminatio
 
 #include "Audacity.h" // This should always be included first
 
+/*
+ * Get Gtk.h and Glib.h included and working around that glib got
+ * a GSocket class now 
+ */
+#include <dlfcn.h>
+#define GSocket GlibGSocket
+#include <gtk/gtk.h>
+#undef GSocket
+
 #include <wx/defs.h>
 #include <wx/app.h>
 #include <wx/docview.h>
@@ -328,8 +337,11 @@ void QuitAudacity()
 // Most of this was taken from nsNativeAppSupportUnix.cpp from Mozilla.
 ///////////////////////////////////////////////////////////////////////////////
 
+/* moved up so it doesn't undefs GSocket from wxgtk */
+/*
 #include <dlfcn.h>
 #include <gtk/gtk.h>
+*/
 
 typedef struct _GnomeProgram GnomeProgram;
 typedef struct _GnomeModuleInfo GnomeModuleInfo;
