--- ./build/libreoffice/oox/util/makefile.mk.orig	2010-11-11 16:18:11.000000000 +0100
+++ ./build/libreoffice/oox/util/makefile.mk	2010-12-20 12:58:30.627567313 +0100
@@ -79,6 +79,7 @@
         $(MSFILTERLIB)	\
         $(UNOTOOLSLIB)	\
         $(XMLOFFLIB)    \
+	-lcrypto \
         $(TOOLSLIB)
 
 # link openssl, copied this bit from ucb/source/ucp/webdav/makefile.mk
