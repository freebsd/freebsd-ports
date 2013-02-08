--- ./src/p_global.h	Sun Jul  7 08:07:23 2002
+++ ../../psybnc.mina/src/p_global.h	Sun Nov 24 18:20:55 2002
@@ -1264,8 +1264,8 @@
 #define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt)); strmncpy(cfunc,__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
 #define pmalloc(n) __pmalloc((n),__FILE__,__FUNCTION__,__LINE__)
 
-#define SSLCERT "key/psybnc.cert.pem"
-#define SSLKEY "key/psybnc.key.pem"
+#define SSLCERT PSYBASE "/key/psybnc.cert.pem"
+#define SSLKEY PSYBASE "/key/psybnc.key.pem"
 
 #ifdef HAVE_SSL
 #ifndef SSLSEC
diff -urN src/p_global.h psybnc.new/src/p_global.h
--- src/p_global.h	2005-06-04 22:22:45.000000000 +0400
+++ src/p_global.h	2008-02-25 23:36:21.000000000 +0300
@@ -972,7 +972,7 @@
 #endif
 
 #ifndef P_MEMORY
-unsigned long *__pmalloc(unsigned long size,char *module,char *function,int line);
+char *__pmalloc(unsigned long size,char *module,char *function,int line);
 void _pfree(void * pointer,char *module, char *function, int line);
 struct usert *user(int usern);
 struct newpeert *newpeer(int usern);
@@ -1267,8 +1267,8 @@
 
 #endif
 
-#define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt)); strmncpy(cfunc,__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
-#define pmalloc(n) __pmalloc((n),__FILE__,__FUNCTION__,__LINE__)
+#define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt)); strmncpy(cfunc,(char*)__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
+#define pmalloc(n) __pmalloc((n),__FILE__,(char*)__FUNCTION__,(int)__LINE__)
 
 #define SSLCERT "key/psybnc.cert.pem"
 #define SSLKEY "key/psybnc.key.pem"
