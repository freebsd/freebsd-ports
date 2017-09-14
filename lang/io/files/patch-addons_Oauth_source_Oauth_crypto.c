--- addons/Oauth/source/Oauth/crypto.c.orig	2017-09-14 12:29:48 UTC
+++ addons/Oauth/source/Oauth/crypto.c
@@ -658,7 +658,7 @@ void sha1_finalize(struct sha1_context *
 	sha1_update(self, bits, 8);
 
 	/* Store state in digest */
-	SHA1Encode(digest, (uint32_t *)self->state, 20);
+	SHA1Encode(digest, self->state, 20);
 
 	/* Zeroize sensitive information.
 	 */
