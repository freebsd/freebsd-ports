--- core/com/lowagie/text/pdf/PdfPKCS7.java.orig	2008-04-08 08:11:56.000000000 +0200
+++ core/com/lowagie/text/pdf/PdfPKCS7.java	2008-04-08 08:14:15.000000000 +0200
@@ -97,7 +97,7 @@
 import org.bouncycastle.asn1.DERUTCTime;
 import org.bouncycastle.jce.provider.X509CRLParser;
 import org.bouncycastle.jce.provider.X509CertParser;
-import org.bouncycastle.util.StreamParsingException;
+import org.bouncycastle.x509.util.StreamParsingException;
 
 /**
  * This class does all the processing related to signing and verifying a PKCS#7
