--- src/vxlog/file-outputter.h.orig	2010-10-18 17:23:04.000000000 +0400
+++ src/vxlog/file-outputter.h	2014-12-12 03:47:01.000000000 +0300
@@ -87,7 +87,11 @@
   VXLOG_DISALLOW_COPY_AND_ASSIGN(FileOutputter);
 };
 
+#ifdef _LIBCPP_VERSION
+typedef std::shared_ptr<FileOutputter> FileOutputterPtr;
+#else
 typedef std::tr1::shared_ptr<FileOutputter> FileOutputterPtr;
+#endif
 
 }  // namespace vxlog
 
