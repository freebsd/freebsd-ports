--- asn1c/unber.c.orig	2013-05-01 16:00:22.000000000 +0200
+++ asn1c/unber.c	2013-05-01 16:00:56.000000000 +0200
@@ -776,3 +776,5 @@
 asn_enc_rval_t OCTET_STRING_encode_uper(asn_TYPE_descriptor_t *td, asn_per_constraints_t *cts, void *sptr, asn_per_outp_t *po) { asn_enc_rval_t er = { 0, 0, 0 }; (void)td; (void)cts; (void)sptr; (void)po; return er; }
 
 int xer_is_whitespace(const void *b, size_t s) { (void)b; (void)s; return 0; }
+
+size_t xer_whitespace_span(const void *chunk_buf, size_t chunk_size) {  (void)chunk_buf; (void)chunk_size; return 0; }
