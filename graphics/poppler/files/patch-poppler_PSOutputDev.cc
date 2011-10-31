--- poppler/PSOutputDev.cc.orig	2011-10-03 23:24:27.000000000 +0200
+++ poppler/PSOutputDev.cc	2011-10-03 23:26:21.000000000 +0200
@@ -1315,7 +1315,7 @@
     writePS("%!PS-Adobe-3.0 Resource-Form\n");
     break;
   }
-  writePSFmt("% Produced by poppler pdftops version: {0:s} (http://poppler.freedesktop.org)\n", PACKAGE_VERSION);
+  writePSFmt("%Produced by poppler pdftops version: {0:s} (http://poppler.freedesktop.org)\n", PACKAGE_VERSION);
   xref->getDocInfo(&info);
   if (info.isDict() && info.dictLookup("Creator", &obj1)->isString()) {
     writePS("%%Creator: ");
