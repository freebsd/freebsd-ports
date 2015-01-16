--- src/vxlog/outputter-interface.h.orig	2010-10-18 17:23:04.000000000 +0400
+++ src/vxlog/outputter-interface.h	2014-12-12 03:46:20.000000000 +0300
@@ -37,7 +37,11 @@
   virtual void Flush() = 0;
 };
 
+#ifdef _LIBCPP_VERSION
+typedef std::shared_ptr<OutputterInterface> SharedOutputterPtr;
+#else
 typedef std::tr1::shared_ptr<OutputterInterface> SharedOutputterPtr;
+#endif
 
 }  // namespace vxlog
 
