--- vendor/src/github.com/spacemonkeygo/openssl/cert.go.orig	2017-07-31 12:00:22.000000000 -0700
+++ vendor/src/github.com/spacemonkeygo/openssl/cert.go	2017-08-18 10:09:51.256599000 -0700
@@ -277,8 +277,8 @@ func (c *Certificate) insecureSign(privKey PrivateKey,
 		md = C.EVP_md_null()
 	case EVP_MD5:
 		md = C.EVP_md5()
-	case EVP_SHA:
-		md = C.EVP_sha()
+	//case EVP_SHA:
+	//	md = C.EVP_sha()
 	case EVP_SHA1:
 		md = C.EVP_sha1()
 	case EVP_DSS:
