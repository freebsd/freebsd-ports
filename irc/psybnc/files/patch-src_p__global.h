--- src/p_global.h.orig	2016-06-20 14:41:27 UTC
+++ src/p_global.h
@@ -972,7 +972,7 @@ int checklogging(int usern);
 #endif
 
 #ifndef P_MEMORY
-unsigned long *__pmalloc(unsigned long size,char *module,char *function,int line);
+char *__pmalloc(unsigned long size,char *module,char *function,int line);
 void _pfree(void * pointer,char *module, char *function, int line);
 struct usert *user(int usern);
 struct newpeert *newpeer(int usern);
@@ -1267,8 +1267,8 @@ extern char * BLOW_stringdecrypt(unsigne
 
 #endif
 
-#define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt)); strmncpy(cfunc,__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
-#define pmalloc(n) __pmalloc((n),__FILE__,__FUNCTION__,__LINE__)
+#define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt)); strmncpy(cfunc,(char*)__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
+#define pmalloc(n) __pmalloc((n),__FILE__,(char*)__FUNCTION__,(int)__LINE__)
 
 #define SSLCERT "key/psybnc.cert.pem"
 #define SSLKEY "key/psybnc.key.pem"
