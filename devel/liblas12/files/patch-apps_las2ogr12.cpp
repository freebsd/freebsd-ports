--- apps/las2ogr12.cpp.orig	2009-10-02 17:48:41 UTC
+++ apps/las2ogr12.cpp
@@ -14,10 +14,10 @@
 #include <vld.h>
 #endif
 // liblas
-#include <liblas/liblas.hpp>
-#include <liblas/laspoint.hpp>
-#include <liblas/lasreader.hpp>
-#include <liblas/cstdint.hpp>
+#include <liblas12/liblas.hpp>
+#include <liblas12/laspoint.hpp>
+#include <liblas12/lasreader.hpp>
+#include <liblas12/cstdint.hpp>
 // ogr
 #include <ogr_api.h>
 //std
@@ -208,7 +208,7 @@ void report_ogr_formats(std::ostream& os)
 
 void usage()
 {
-    std::cerr << "Usage: las2ogr OPTIONS\nOptions are:\n"
+    std::cerr << "Usage: las2ogr12 OPTIONS\nOptions are:\n"
         << "\t-h print this message\n"
         << "\t-i <infile>\tinput ASPRS LAS file\n"
         << "\t-o <outfile>\toutput file\n"
