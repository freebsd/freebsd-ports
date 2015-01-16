--- src/vxlog/logger.h.orig	2010-10-18 17:23:04.000000000 +0400
+++ src/vxlog/logger.h	2014-12-12 03:13:44.000000000 +0300
@@ -45,7 +45,12 @@
 
   template<typename OutputterT>
   static void BindOutputter(Level::Type level,
+#ifdef _LIBCPP_VERSION
+                            std::shared_ptr<OutputterT> outputter) {
+#else
                             std::tr1::shared_ptr<OutputterT> outputter) {
+#endif
+
     OutputterHolder<ModuleT, Level::kDebug>::Reset();
     OutputterHolder<ModuleT, Level::kInfo>::Reset();
     OutputterHolder<ModuleT, Level::kWarn>::Reset();
