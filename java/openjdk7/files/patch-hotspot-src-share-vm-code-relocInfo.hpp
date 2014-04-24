--- hotspot/src/share/vm/code/relocInfo.hpp.orig	2013-09-06 14:22:10.000000000 -0400
+++ hotspot/src/share/vm/code/relocInfo.hpp	2014-04-21 16:06:19.000000000 -0400
@@ -371,7 +371,7 @@
   // "immediate" in the prefix header word itself.  This optimization
   // is invisible outside this module.)
 
-  inline friend relocInfo prefix_relocInfo(int datalen = 0);
+  inline friend relocInfo prefix_relocInfo(int datalen);
 
  protected:
   // an immediate relocInfo optimizes a prefix with one 10-bit unsigned value
@@ -466,7 +466,7 @@
   return relocInfo(relocInfo::none, relocInfo::offset_limit() - relocInfo::offset_unit);
 }
 
-inline relocInfo prefix_relocInfo(int datalen) {
+inline relocInfo prefix_relocInfo(int datalen = 0) {
   assert(relocInfo::fits_into_immediate(datalen), "datalen in limits");
   return relocInfo(relocInfo::data_prefix_tag, relocInfo::RAW_BITS, relocInfo::datalen_tag | datalen);
 }
