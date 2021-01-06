--- src/fractgen.cc.orig	2021-01-06 00:19:32 UTC
+++ src/fractgen.cc
@@ -34,7 +34,7 @@ int main(int argc, char *argv[])
    QTranslator applicationTranslator;
    if(!applicationTranslator.load("fractgen_" + QLocale::system().name())) {
       applicationTranslator.load("fractgen_" + QLocale::system().name(),
-                                 "/usr/share/fractgen");
+                                 "%%PREFIX%%/share/fractgen");
    }
    application.installTranslator(&applicationTranslator);
 
