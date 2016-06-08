--- protocols/examples/INet/HTTP_Simple_exec.cpp.orig	2014-12-29 10:41:20 UTC
+++ protocols/examples/INet/HTTP_Simple_exec.cpp
@@ -18,7 +18,7 @@ u_short proxy_port = ACE::HTTP::URL::HTT
 ACE_CString url;
 ACE_CString outfile;
 #if defined (ACE_HAS_SSL) && ACE_HAS_SSL == 1
-int ssl_mode = ACE_SSL_Context::SSLv3;
+int ssl_mode = ACE_SSL_Context::SSLv23;
 bool verify_peer = true;
 bool ignore_verify = false;
 ACE_CString certificate;
