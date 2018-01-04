--- api/api-swig.hh.orig	2009-03-19 13:00:11 UTC
+++ api/api-swig.hh
@@ -22,7 +22,7 @@
 %include "cstring.i"
 %include "std_string.i"
 
-# manually include it, otherwise SWIG will not source it
+/* manually include it, otherwise SWIG will not source it */
 %include "config.h"
 
 %{
