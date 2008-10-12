--- digikam/showfoto/main.cpp.orig	2008-10-12 15:05:29.000000000 +0200
+++ digikam/showfoto/main.cpp	2008-10-12 15:06:03.000000000 +0200
@@ -45,7 +45,6 @@
 // Libkdcraw includes.
 
 #include <libkdcraw/kdcraw.h>
-#include <libkdcraw/dcrawbinary.h>
 
 // C Ansi includes.
 
@@ -66,7 +65,7 @@ static KCmdLineOptions options[] =
 
 int main(int argc, char *argv[])
 {
-    QString DcrawVer    = KDcrawIface::DcrawBinary::internalVersion();
+    QString DcrawVer    = KDcrawIface::KDcraw::librawVersion();
 
     QString Exiv2Ver    = KExiv2Iface::KExiv2::Exiv2Version();
 
@@ -84,7 +83,7 @@ int main(int argc, char *argv[])
                           QString("\n") +                           
                           QString(I18N_NOOP("Using KDcraw library version %1")).arg(KDcrawIface::KDcraw::version()) +
                           QString("\n") +                           
-                          QString(I18N_NOOP("Using Dcraw program version %1")).arg(DcrawVer) +
+                          QString(I18N_NOOP("Using LibRaw library version %1")).arg(DcrawVer) +
                           QString("\n") +                           
                           QString(I18N_NOOP("Using PNG library version %1")).arg(PNG_LIBPNG_VER_STRING);
 
