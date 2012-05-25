--- libraries/fcollada/src/FCollada/FUtils/FUStringBuilder.hpp.orig	2012-05-21 22:08:59.267251130 +0200
+++ libraries/fcollada/src/FCollada/FUtils/FUStringBuilder.hpp	2012-05-21 22:13:05.450463479 +0200
@@ -18,6 +18,42 @@
 #include <float.h>
 #endif
 
+#ifdef __FreeBSD__
+// ecvt is not included in FreeBSD's stdlib
+// http://forum.pellesc.de/index.php?PHPSESSID=0c4srgu3vrs19ali5459jehdh3&topic=2103.msg7797#msg7797
+char *ecvt(double value, int ndigit, int *decpt, int *sign)
+{
+	static char buffer[348];
+	static const int n = sizeof(buffer)/sizeof(buffer[0])-1;
+	ptrdiff_t pd;
+	int len;
+	int zeros=0;
+	if (ndigit > n) ndigit=n;
+	while (value > -1.0 && value < 1.0 ) {
+		value*=10.0;
+		zeros++;
+	}
+	sprintf(buffer,"%.*f",DBL_DIG,value);
+	len=strlen(buffer);
+	if (buffer[0]=='-') {
+		memmove(buffer, buffer+1, --len);
+		buffer[len]='\0';
+		*sign=1;
+	}
+	else *sign = 0;
+	pd=strchr(buffer,'.')-buffer;
+	memmove(buffer+pd,buffer+pd+1,--len-pd);
+	buffer[len]='\0';
+	*decpt=(int)pd-zeros;
+	if (len >= ndigit) buffer[ndigit]='\0';
+	else {
+		memset(buffer+len,'0',ndigit-len);
+		buffer[ndigit]='\0';
+	}
+	return buffer;
+}
+#endif
+
 #ifdef WIN32
 #define ecvt _ecvt
 #endif // WIN32
