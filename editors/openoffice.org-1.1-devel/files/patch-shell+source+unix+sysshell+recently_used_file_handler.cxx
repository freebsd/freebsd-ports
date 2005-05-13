Issutracker : #iXXXXX#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : 
In solver/645/unxfbsd.pro/inc/rtl/string.hxx,
even though there is a descrioptin like
static OString valueOf( sal_Int32 i, sal_Int16 radix = 10 ) SAL_THROW(())
and In /usr/include/machine/_types.h, 
typedef int                     __int32_t;
typedef __int32_t       __time_t;               /* time()... */
and
/usr/include/time.h:typedef     __time_t        time_t;
this cast seems to be mandatory. Why??

--- shell/source/unix/sysshell/recently_used_file_handler.cxx.orig	Tue Jan 13 00:56:37 2004
+++ shell/source/unix/sysshell/recently_used_file_handler.cxx	Tue Jan 13 00:57:26 2004
@@ -188,9 +188,12 @@
             write_xml_start_tag(TAG_RECENT_ITEM, file, true);
             write_xml_tag(TAG_URI, uri_, file);
             write_xml_tag(TAG_MIME_TYPE, mime_type_, file);
-                                
-            rtl::OString ts = rtl::OString::valueOf(timestamp_);            
-            write_xml_tag(TAG_TIMESTAMP, ts.getStr(), file);
+#if defined FREEBSD
+            rtl::OString ts = rtl::OString::valueOf((sal_Int32)timestamp_);
+#else
+            rtl::OString ts = rtl::OString::valueOf(timestamp_);            
+#endif
+	  write_xml_tag(TAG_TIMESTAMP, ts.getStr(), file);
                         
             if (is_private_)            
                 write_xml_tag(TAG_PRIVATE, file);                               
