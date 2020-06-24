--- src/electronics/components/probe.cpp.orig	2020-06-24 06:28:05 UTC
+++ src/electronics/components/probe.cpp
@@ -20,6 +20,7 @@
 
 #include <klocalizedstring.h>
 #include <qpainter.h>
+#include <qpainterpath.h>
 
 //BEGIN class Probe
 Probe::Probe( ICNDocument *icnDocument, bool newItem, const char *id )
