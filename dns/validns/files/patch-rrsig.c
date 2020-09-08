--- rrsig.c.orig	2014-02-11 20:45:39 UTC
+++ rrsig.c
@@ -26,7 +26,7 @@
 struct verification_data
 {
 	struct verification_data *next;
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx;
 	struct rr_dnskey *key;
 	struct rr_rrsig *rr;
 	int ok;
@@ -180,7 +180,8 @@ void *verification_thread(void *dummy)
 		if (d) {
 			int r;
 			d->next = NULL;
-			r = EVP_VerifyFinal(&d->ctx, (unsigned char *)d->rr->signature.data, d->rr->signature.length, d->key->pkey);
+			r = EVP_VerifyFinal(d->ctx, (unsigned char *)d->rr->signature.data, d->rr->signature.length, d->key->pkey);
+			EVP_MD_CTX_destroy(d->ctx);
 			if (r == 1) {
 				d->ok = 1;
 			} else {
@@ -232,7 +233,8 @@ static void schedule_verification(struct verification_
 	} else {
 		int r;
 		G.stats.signatures_verified++;
-		r = EVP_VerifyFinal(&d->ctx, (unsigned char *)d->rr->signature.data, d->rr->signature.length, d->key->pkey);
+		r = EVP_VerifyFinal(d->ctx, (unsigned char *)d->rr->signature.data, d->rr->signature.length, d->key->pkey);
+		EVP_MD_CTX_destroy(d->ctx);
 		if (r == 1) {
 			d->ok = 1;
 		} else {
@@ -250,21 +252,21 @@ static int verify_signature(struct verification_data *
 	struct rr *signed_rr;
 	int i;
 
-	EVP_MD_CTX_init(&d->ctx);
+	d->ctx = EVP_MD_CTX_create();
 	switch (d->rr->algorithm) {
 	case ALG_DSA:
 	case ALG_RSASHA1:
 	case ALG_DSA_NSEC3_SHA1:
 	case ALG_RSASHA1_NSEC3_SHA1:
-		if (EVP_VerifyInit(&d->ctx, EVP_sha1()) != 1)
+		if (EVP_VerifyInit(d->ctx, EVP_sha1()) != 1)
 			return 0;
 		break;
 	case ALG_RSASHA256:
-		if (EVP_VerifyInit(&d->ctx, EVP_sha256()) != 1)
+		if (EVP_VerifyInit(d->ctx, EVP_sha256()) != 1)
 			return 0;
 		break;
 	case ALG_RSASHA512:
-		if (EVP_VerifyInit(&d->ctx, EVP_sha512()) != 1)
+		if (EVP_VerifyInit(d->ctx, EVP_sha512()) != 1)
 			return 0;
 		break;
 	default:
@@ -274,7 +276,7 @@ static int verify_signature(struct verification_data *
 	chunk = rrsig_wirerdata_ex(&d->rr->rr, 0);
 	if (chunk.length < 0)
 		return 0;
-	EVP_VerifyUpdate(&d->ctx, chunk.data, chunk.length);
+	EVP_VerifyUpdate(d->ctx, chunk.data, chunk.length);
 
 	set = getmem_temp(sizeof(*set) * signed_set->count);
 
@@ -294,12 +296,12 @@ static int verify_signature(struct verification_data *
 		chunk = name2wire_name(signed_set->named_rr->name);
 		if (chunk.length < 0)
 			return 0;
-		EVP_VerifyUpdate(&d->ctx, chunk.data, chunk.length);
-		b2 = htons(set[i].rr->rdtype);    EVP_VerifyUpdate(&d->ctx, &b2, 2);
-		b2 = htons(1);  /* class IN */   EVP_VerifyUpdate(&d->ctx, &b2, 2);
-		b4 = htonl(set[i].rr->ttl);       EVP_VerifyUpdate(&d->ctx, &b4, 4);
-		b2 = htons(set[i].wired.length); EVP_VerifyUpdate(&d->ctx, &b2, 2);
-		EVP_VerifyUpdate(&d->ctx, set[i].wired.data, set[i].wired.length);
+		EVP_VerifyUpdate(d->ctx, chunk.data, chunk.length);
+		b2 = htons(set[i].rr->rdtype);    EVP_VerifyUpdate(d->ctx, &b2, 2);
+		b2 = htons(1);  /* class IN */   EVP_VerifyUpdate(d->ctx, &b2, 2);
+		b4 = htonl(set[i].rr->ttl);       EVP_VerifyUpdate(d->ctx, &b4, 4);
+		b2 = htons(set[i].wired.length); EVP_VerifyUpdate(d->ctx, &b2, 2);
+		EVP_VerifyUpdate(d->ctx, set[i].wired.data, set[i].wired.length);
 	}
 
 	schedule_verification(d);
