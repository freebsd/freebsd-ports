--- hexfile.h.orig	Tue Nov 19 12:23:13 2002
+++ hexfile.h	Tue Nov 19 12:23:46 2002
@@ -43,7 +43,7 @@
 #ifndef H_HEXFILE
 #define H_HEXFILE
 
-#include <fstream.h>
+#include <fstream>
 
 #include "picport.h"
 
@@ -57,8 +57,8 @@
   enum formats { unknown = 0, ihx8m, ihx16 };
 
 private:
-  void save_line (ofstream& f, int begin, int len, enum formats format) const;
-  void save_region (ofstream& f, int addr, int end, enum formats format, bool skip_ones) const;
+  void save_line (std::ofstream& f, int begin, int len, enum formats format) const;
+  void save_region (std::ofstream& f, int addr, int end, enum formats format, bool skip_ones) const;
 public:
 
   hexfile () {
