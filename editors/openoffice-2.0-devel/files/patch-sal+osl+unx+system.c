--- ../sal/osl/unx/system.c.orig	Tue Aug 20 15:49:46 2002
+++ ../sal/osl/unx/system.c	Thu Apr  3 21:56:32 2003
@@ -74,7 +74,7 @@
 static pthread_mutex_t getrtl_mutex = PTHREAD_MUTEX_INITIALIZER;
 
 /* struct passwd differs on some platforms */
-#if defined NETBSD || defined MACOSX || defined FREEBSD
+#if defined NETBSD || defined FREEBSD || defined MACOSX
 #include <pwd.h>
 #include <sys/types.h>
 
@@ -134,7 +134,6 @@
   	return res;
 }
 
-#if defined(NETBSD) || defined(MACOSX)
 int getpwuid_r(uid_t uid, struct passwd *pwd, char *buffer,
            size_t buflen, struct passwd **result)
 {
@@ -201,8 +200,8 @@
 
   return res;
 }
-#endif
 
+#if defined NETBSD || defined MACOSX
 struct tm *localtime_r(const time_t *timep, struct tm *buffer)
 {
 	struct tm* res;
@@ -236,7 +235,8 @@
 
 	return res;
 }
-#endif  /* defined NETBSD || defined MACOSX */
+#endif  /* defined NETBSD || MACOSX */
+#endif  /* defined NETBSD || FREEBSD || MACOSX */
 
 #ifdef SCO
 #include <pwd.h>
@@ -712,3 +712,50 @@
 }
 #endif
 
+#if defined(NETBSD) || defined(FREEBSD)
+char *fcvt(double value, int ndigit, int *decpt, int *sign)
+{
+  static char ret[256];
+  char buf[256],zahl[256],format[256]="%";
+  char *v1,*v2;
+ 
+  if (value==0.0) value=1e-30;
+  
+  if (value<0.0) *sign=1; else *sign=0;
+ 
+  if (value<1.0) 
+  {
+    *decpt=(int)log10(value); 
+	value*=pow(10.0,1-*decpt);
+	ndigit+=*decpt-1;
+	if (ndigit<0) ndigit=0;
+  }
+  else 
+  {
+    *decpt=(int)log10(value)+1;
+  }
+  
+  sprintf(zahl,"%d",ndigit);
+  strcat(format,zahl);
+  strcat(format,".");
+  strcat(format,zahl);
+  strcat(format,"f");
+  
+  sprintf(buf,format,value);
+  
+  if (ndigit!=0)
+  {
+    v1=strtok(buf,".");
+    v2=strtok(NULL,".");
+	strcpy(ret,v1);
+    strcat(ret,v2);
+  }
+  else
+  {
+    strcpy(ret,buf);
+  }
+    
+  return(ret);
+}
+
+#endif
