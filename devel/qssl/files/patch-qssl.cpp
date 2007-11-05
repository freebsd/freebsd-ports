--- qssl.cpp.orig	2003-06-01 00:37:38.000000000 +0200
+++ qssl.cpp	2007-11-04 21:16:18.000000000 +0100
@@ -18,6 +18,8 @@
  *
  */
 
+#include<sys/param.h>   /* see line 471 */
+
 #include"qssl_p.h"
 
 #include<qstring.h>
@@ -147,10 +149,10 @@
 	c = d = 0;
 
 	for( i = 0; i < len; i += 4 ) {
-		a = tbl[s[i]];
-		b = tbl[s[i + 1]];
-		c = tbl[s[i + 2]];
-		d = tbl[s[i + 3]];
+		a = tbl[(unsigned char)s[i]];
+		b = tbl[(unsigned char)s[i + 1]];
+		c = tbl[(unsigned char)s[i + 2]];
+		d = tbl[(unsigned char)s[i + 3]];
 		if((a == 64 || b == 64) || (a < 0 || b < 0 || c < 0 || d < 0)) {
 			p.resize(0);
 			return p;
@@ -466,7 +468,12 @@
 	memcpy(enc.data(), cs.data(), enc.size());
 	QByteArray dat = base64decode(enc);
 	unsigned char *p = (unsigned char *)dat.data();
+#if (__FreeBSD_version >= 700042)
+	X509 *x = d2i_X509(NULL, (const unsigned char **)&p, dat.size());
+#else
 	X509 *x = d2i_X509(NULL, &p, dat.size());
+#endif
+
 	if(!x)
 		return false;
 	fromX509(x);
