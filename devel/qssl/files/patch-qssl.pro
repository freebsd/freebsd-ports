--- qssl.pro~	Sun Nov 10 09:16:44 2002
+++ qssl.pro	Sun Nov 10 09:16:49 2002
@@ -8,5 +8,5 @@
 SOURCES = qssl.cpp
 
 # link with OpenSSL
-LIBS += -lssl
+LIBS += -lssl -lcrypto
 
