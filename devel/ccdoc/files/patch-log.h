--- log.h.orig	2018-08-26 04:31:27 UTC
+++ log.h
@@ -69,7 +69,6 @@ namespace ccdoc {
     log& operator << (unsigned int);
     log& operator << (long);
     log& operator << (unsigned long);
-    log& operator << (ostream& (fct)(ostream&));
     log& operator << (log& x) {return x;}
     log& flush();
     void insert(ostream*);
