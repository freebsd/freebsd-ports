--- ssl.c.orig	2021-08-02 06:24:35 UTC
+++ ssl.c
@@ -93,10 +93,12 @@ ssl_init(struct vsf_session* p_sess)
     {
       options |= SSL_OP_NO_TLSv1_2;
     }
+#ifdef SSL_OP_NO_TLSv1_3
     if (!tunable_tlsv1_3)
     {
       options |= SSL_OP_NO_TLSv1_3;
     }
+#endif
     SSL_CTX_set_options(p_ctx, options);
     if (tunable_rsa_cert_file)
     {
