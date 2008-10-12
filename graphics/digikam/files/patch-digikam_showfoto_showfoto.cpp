--- digikam/showfoto/showfoto.cpp.orig	2008-10-12 15:04:49.000000000 +0200
+++ digikam/showfoto/showfoto.cpp	2008-10-12 15:05:20.000000000 +0200
@@ -73,7 +73,7 @@ extern "C"
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -179,7 +179,6 @@ ShowFoto::ShowFoto(const KURL::List& url
     if(d->splash)
         d->splash->message(i18n("Checking dcraw version"), AlignLeft, white);
 
-    KDcrawIface::DcrawBinary::instance()->checkSystem();
 
     // Populate Themes
 
@@ -370,7 +369,6 @@ void ShowFoto::show()
 
     // Report errors from dcraw detection.
 
-    KDcrawIface::DcrawBinary::instance()->checkReport();  
 }
 
 void ShowFoto::setupConnections()
@@ -832,7 +830,7 @@ void ShowFoto::openFolder(const KURL& ur
     // Added RAW files estentions supported by dcraw program and 
     // defines to digikam/libs/dcraw/rawfiles.h
     filter.append (" ");
-    filter.append ( QString(KDcrawIface::DcrawBinary::instance()->rawFiles()) );  
+    filter.append ( QString(KDcrawIface::KDcraw::rawFiles()) );  
     filter.append (" ");
 
     QString patterns = filter.lower();
