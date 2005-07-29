--- sal/osl/unx/system.c.orig	Tue Aug 20 08:49:46 2002
+++ sal/osl/unx/system.c	Sat Apr 19 22:15:25 2003
@@ -74,7 +74,8 @@
 static pthread_mutex_t getrtl_mutex = PTHREAD_MUTEX_INITIALIZER;
 
 /* struct passwd differs on some platforms */
-#if defined NETBSD || defined MACOSX || defined FREEBSD
+#if defined NETBSD || defined MACOSX || \
+	(defined FREEBSD && (__FreeBSD_version < 500112))
 #include <pwd.h>
 #include <sys/types.h>
 
@@ -203,6 +204,73 @@
 }
 #endif
 
+int getpwuid_r(uid_t uid, struct passwd *pwd, char *buffer,
+           size_t buflen, struct passwd **result)
+{
+  struct passwd* res;
+
+  pthread_mutex_lock(&getrtl_mutex);
+
+  if ( res = getpwuid(uid) )
+  {
+    size_t pw_name, pw_passwd, pw_class, pw_gecos, pw_dir, pw_shell;
+
+    pw_name = strlen(res->pw_name)+1;
+    pw_passwd = strlen(res->pw_passwd)+1;
+    pw_class = strlen(res->pw_class)+1;
+    pw_gecos = strlen(res->pw_gecos)+1;
+    pw_dir = strlen(res->pw_dir)+1;
+    pw_shell = strlen(res->pw_shell)+1;
+
+    if (pw_name+pw_passwd+pw_class+pw_gecos
+                                 +pw_dir+pw_shell < buflen)
+    {
+      memcpy(pwd, res, sizeof(struct passwd));
+
+      strncpy(buffer, res->pw_name, pw_name);
+      pwd->pw_name = buffer;
+      buffer += pw_name;
+
+      strncpy(buffer, res->pw_passwd, pw_passwd);
+      pwd->pw_passwd = buffer;
+      buffer += pw_passwd;
+
+      strncpy(buffer, res->pw_class, pw_class);
+      pwd->pw_class = buffer;
+      buffer += pw_class;
+
+      strncpy(buffer, res->pw_gecos, pw_gecos);
+      pwd->pw_gecos = buffer;
+      buffer += pw_gecos;
+
+      strncpy(buffer, res->pw_dir, pw_dir);
+      pwd->pw_dir = buffer;
+      buffer += pw_dir;
+
+      strncpy(buffer, res->pw_shell, pw_shell);
+      pwd->pw_shell = buffer;
+      buffer += pw_shell;
+
+      *result = pwd ;
+      res = 0 ;
+
+    } else {
+
+      res = ENOMEM ;
+
+    }      
+  
+  } else {
+
+    res = errno ;
+ 
+  } 
+
+  pthread_mutex_unlock(&getrtl_mutex);
+
+  return res;
+}
+
 struct tm *localtime_r(const time_t *timep, struct tm *buffer)
 {
 	struct tm* res;
@@ -712,3 +780,50 @@
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
