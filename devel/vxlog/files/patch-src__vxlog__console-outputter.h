--- src/vxlog/console-outputter.h.orig	2010-10-18 17:23:04.000000000 +0400
+++ src/vxlog/console-outputter.h	2014-12-12 03:12:09.000000000 +0300
@@ -52,7 +52,11 @@
   VXLOG_DISALLOW_COPY_AND_ASSIGN(ConsoleOutputter);
 };
 
+#ifdef _LIBCPP_VERSION
+typedef std::shared_ptr<ConsoleOutputter> ConsoleOutputterPtr;
+#else
 typedef std::tr1::shared_ptr<ConsoleOutputter> ConsoleOutputterPtr;
+#endif
 
 }  // namespace vxlog
 
