--- nsec3checks.c.orig	2014-02-11 20:46:07 UTC
+++ nsec3checks.c
@@ -28,7 +28,7 @@
 static struct binary_data name2hash(char *name, struct rr *param)
 {
     struct rr_nsec3param *p = (struct rr_nsec3param *)param;
-	EVP_MD_CTX ctx;
+	EVP_MD_CTX *ctx;
 	unsigned char md0[EVP_MAX_MD_SIZE];
 	unsigned char md1[EVP_MAX_MD_SIZE];
 	unsigned char *md[2];
@@ -45,26 +45,28 @@ static struct binary_data name2hash(char *name, struct
 
 	/* XXX Maybe use Init_ex and Final_ex for speed? */
 
-	EVP_MD_CTX_init(&ctx);
-	if (EVP_DigestInit(&ctx, EVP_sha1()) != 1)
-		return r;
-	digest_size = EVP_MD_CTX_size(&ctx);
-	EVP_DigestUpdate(&ctx, wire_name.data, wire_name.length);
-	EVP_DigestUpdate(&ctx, p->salt.data, p->salt.length);
-	EVP_DigestFinal(&ctx, md[mdi], NULL);
+	ctx = EVP_MD_CTX_create();
+	if (EVP_DigestInit(ctx, EVP_sha1()) != 1)
+		goto out;
+	digest_size = EVP_MD_CTX_size(ctx);
+	EVP_DigestUpdate(ctx, wire_name.data, wire_name.length);
+	EVP_DigestUpdate(ctx, p->salt.data, p->salt.length);
+	EVP_DigestFinal(ctx, md[mdi], NULL);
 
 	for (i = 0; i < p->iterations; i++) {
-		if (EVP_DigestInit(&ctx, EVP_sha1()) != 1)
-			return r;
-		EVP_DigestUpdate(&ctx, md[mdi], digest_size);
+		if (EVP_DigestInit(ctx, EVP_sha1()) != 1)
+			goto out;
+		EVP_DigestUpdate(ctx, md[mdi], digest_size);
 		mdi = (mdi + 1) % 2;
-		EVP_DigestUpdate(&ctx, p->salt.data, p->salt.length);
-		EVP_DigestFinal(&ctx, md[mdi], NULL);
+		EVP_DigestUpdate(ctx, p->salt.data, p->salt.length);
+		EVP_DigestFinal(ctx, md[mdi], NULL);
 	}
 
 	r.length = digest_size;
 	r.data = getmem(digest_size);
 	memcpy(r.data, md[mdi], digest_size);
+ out:
+	EVP_MD_CTX_destroy(ctx);
 	return r;
 }
 
