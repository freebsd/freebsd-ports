--- common/gsm-encoding.c.orig	Sat Nov  8 12:15:34 2003
+++ common/gsm-encoding.c	Wed Dec  3 22:09:31 2003
@@ -591,14 +591,16 @@
 	size_t outleft, inleft, nconv;
 	char *pin, *pout;
 
+#if defined(HAVE_ICONV) && defined(HAVE_LANGINFO_CODESET)
+	iconv_t cd;
+#endif
+
 	outleft = outlen;
 	inleft = inlen;
 	pin = (char *)instring;
 	pout = outstring;
 
 #if defined(HAVE_ICONV) && defined(HAVE_LANGINFO_CODESET)
-	iconv_t cd;
-
 	cd = iconv_open("UTF-8", nl_langinfo(CODESET));
 
 	nconv = iconv(cd, &pin, &inleft, &pout, &outleft);
