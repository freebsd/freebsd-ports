--- kent/src/inc/common.mk.orig	2021-04-02 22:47:03 UTC
+++ kent/src/inc/common.mk
@@ -61,6 +61,10 @@ else
   endif
 endif
 
+ifeq ($(UNAME_S),FreeBSD)
+  ICONVLIB=-L${LOCALBASE}/lib -liconv
+endif
+
 # autodetect if openssl is installed
 ifeq (${SSLDIR},)
   SSLDIR = /usr/include/openssl
