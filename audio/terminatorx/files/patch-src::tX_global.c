--- src/tX_global.c.orig	Thu Apr 17 04:45:56 2003
+++ src/tX_global.c	Thu Apr 24 21:21:59 2003
@@ -230,7 +230,7 @@
 	char indent[]="\t";
 	FILE *rc=NULL;
 	gzFile rz=NULL;
-	_store_compress_xml=0;
+	int _store_compress_xml=0;
 	char tmp_xml_buffer[4096];
 	
 	get_rc_name(rc_name);
@@ -314,7 +314,7 @@
 }
 
 char *encode_xml(char *dest, const char *src) {
-	int i, t, max;
+	int i, t, max, inlen, outlen, res;
 	char tmp[4096];
 	
 	tmp[0]=0;
@@ -333,10 +333,10 @@
 	}
 	tmp[t]=0;
 
-	int outlen=4096;
-	int inlen=t;
+	outlen=4096;
+	inlen=t;
 	
-	int res=isolat1ToUTF8((unsigned char *) dest, &outlen, (unsigned char *) tmp, &inlen);
+	res=isolat1ToUTF8((unsigned char *) dest, &outlen, (unsigned char *) tmp, &inlen);
 	dest[outlen]=0;
 	if (res<0) {
 		tX_error("failed to encode string (%s) to UTF-8.", src);
