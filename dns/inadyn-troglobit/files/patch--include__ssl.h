--- include/ssl.h.org	2017-09-18 21:19:05 UTC
+++ include/ssl.h
@@ -34,7 +34,7 @@
  * For more excellent information on the topic, see this blog post
  * https://www.happyassassin.net/2015/01/12/a-note-about-ssltls-trusted-certificate-stores-and-platforms/
  */
-#define CAFILE1 "/etc/ssl/certs/ca-certificates.crt"
+#define CAFILE1 "/usr/local/share/certs/ca-root-nss.crt"
 #define CAFILE2 "/etc/pki/tls/certs/ca-bundle.trust.crt"

 /* User can supply local CA PEM bundle in .conf file */
