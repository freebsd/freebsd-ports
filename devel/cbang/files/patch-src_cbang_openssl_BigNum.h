--- src/cbang/openssl/BigNum.h.orig	2022-09-17 22:00:36 UTC
+++ src/cbang/openssl/BigNum.h
@@ -48,6 +48,7 @@ namespace cb {
     ~BigNum();
 
     BIGNUM *get() const {return bn;}
+    BIGNUM *adopt() {deallocate = false; return bn;}
     bool isNull() const {return !bn;}
     unsigned size() const;
     std::string toBinString() const;
