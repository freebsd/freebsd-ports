--- lib/Redis/Fast.pm.orig	2024-03-08 16:30:35 UTC
+++ lib/Redis/Fast.pm
@@ -243,6 +243,7 @@ sub new {
   $self->__set_ssl($args{ssl} || 0);
   if ($args{ssl} && SSL_AVAILABLE && $args{SSL_verify_mode}) {
     # To pass the SSL verify mode to the underlying bindings, we'll use a string
+    no strict 'subs';
     $self->__set_ssl_verify_mode("SSL_VERIFY_NONE") if ($args{SSL_verify_mode} == IO::Socket::SSL::SSL_VERIFY_NONE);
     $self->__set_ssl_verify_mode("SSL_VERIFY_PEER") if ($args{SSL_verify_mode} == IO::Socket::SSL::SSL_VERIFY_PEER);
     $self->__set_ssl_verify_mode("SSL_VERIFY_FAIL_IF_NO_PEER_CERT") if ($args{SSL_verify_mode} == IO::Socket::SSL::SSL_VERIFY_FAIL_IF_NO_PEER_CERT);
