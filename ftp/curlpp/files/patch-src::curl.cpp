Index: src/curl.cpp
===================================================================
RCS file: /home/cvs/ringlet/c/contrib/net/curlpp/src/curl.cpp,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -r1.1.1.1 -r1.2
--- src/curl.cpp	13 Apr 2004 17:20:29 -0000	1.1.1.1
+++ src/curl.cpp	20 Apr 2004 11:18:15 -0000	1.2
@@ -193,13 +193,21 @@
 void 
 curlpp::curl::passwd_function( passwd_function_t function )
 {
+#if LIBCURL_VERSION_NUM < 0x070b01
    option( CURLOPT_PASSWDFUNCTION, ( void * ) function );
+#else
+   runtime_assert( false, "The CURLOPT_PASSWDFUNCTION option has been deprecated." );
+#endif
 }
 
 void
 curlpp::curl::passwd_data( passwd_trait *trait )
 {
+#if LIBCURL_VERSION_NUM < 0x070b01
    option( CURLOPT_PASSWDDATA, static_cast< void * >( trait ) );
+#else
+   runtime_assert( false, "The CURLOPT_PASSWDDATA option has been deprecated." );
+#endif
 }
 
 void
