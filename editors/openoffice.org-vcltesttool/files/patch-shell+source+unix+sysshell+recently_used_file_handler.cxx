http://qa.openoffice.org/issues/show_bug.cgi?id=24315

For FreeBSD, time_t is defined as 
at /usr/include/machine/_types.h 
49th typedef int                     __int32_t;
90th typedef __int32_t       __time_t;               /* time()... */
and 
/usr/include/pwd.h:typedef      __time_t        time_t;
/usr/include/time.h:typedef     __time_t        time_t;
/usr/include/timeconv.h:typedef __time_t        time_t;
/usr/include/utime.h:typedef    __time_t        time_t;
so time_t is equal to 32 bit integer

For LinuxPPC (Yellowdog 3.0.1)


--- ../shell/source/unix/sysshell/recently_used_file_handler.cxx.orig	Tue Jan 13 00:56:37 2004
+++ ../shell/source/unix/sysshell/recently_used_file_handler.cxx	Tue Jan 13 00:57:26 2004
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
