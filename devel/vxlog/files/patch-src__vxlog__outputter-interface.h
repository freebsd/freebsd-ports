--- src/vxlog/outputter-interface.h.orig	2010-10-18 13:23:04 UTC
+++ src/vxlog/outputter-interface.h
@@ -23,7 +23,7 @@
 #ifndef VOLVOX_VXLOG_OUTPUTTER_INTERFACE_H_
 #define VOLVOX_VXLOG_OUTPUTTER_INTERFACE_H_
 
-#include <tr1/memory>
+#include <memory>
 #include "vxlog/level.h"
 
 namespace vxlog {
@@ -37,7 +37,11 @@ class OutputterInterface {
   virtual void Flush() = 0;
 };
 
+#ifdef _LIBCPP_VERSION
+typedef std::shared_ptr<OutputterInterface> SharedOutputterPtr;
+#else
 typedef std::tr1::shared_ptr<OutputterInterface> SharedOutputterPtr;
+#endif
 
 }  // namespace vxlog
 
