--- ./src/Mod/Mesh/App/Core/MeshIO.cpp.orig	Sat Feb 24 11:34:01 2007
+++ ./src/Mod/Mesh/App/Core/MeshIO.cpp	Sun Apr 22 22:02:35 2007
@@ -38,6 +38,55 @@
 
 #include <math.h>
 
+#if defined(FC_OS_NETBSD) || defined(FC_OS_FREEBSD)
+// Borrowed from the FreeBSD port editors/openoffice.org-1.0
+
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
 
 using namespace MeshCore;
 
