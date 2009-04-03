--- src/libxorsa/xorsa_plot_area.h.orig	2005-01-05 11:25:06.000000000 +0900
+++ src/libxorsa/xorsa_plot_area.h	2009-04-02 13:48:37.000000000 +0900
@@ -57,7 +57,7 @@
   }
 }
 
-extern char *MonthNameShort[13]; // sdncal.h
+extern "C" char *MonthNameShort[13]; // sdncal.h
 
 void FineDate(QString & label, const orsa::UniverseTypeAwareTime & t, bool=true);
 void FineDate_HMS(QString & label, const orsa::UniverseTypeAwareTime & t);
