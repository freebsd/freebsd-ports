--- src/vxlog/syslog-outputter.h.orig	2010-10-18 17:23:04.000000000 +0400
+++ src/vxlog/syslog-outputter.h	2014-12-12 03:13:03.000000000 +0300
@@ -49,7 +49,11 @@
   VXLOG_DISALLOW_COPY_AND_ASSIGN(SyslogOutputter);
 };
 
+#ifdef _LIBCPP_VERSION
+typedef std::shared_ptr<SyslogOutputter> SyslogOutputterPtr;
+#else
 typedef std::tr1::shared_ptr<SyslogOutputter> SyslogOutputterPtr;
+#endif
 
 }  // namespace vxlog
 
