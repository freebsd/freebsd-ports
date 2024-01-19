--- src/main.cpp.orig	2023-12-26 00:00:15 UTC
+++ src/main.cpp
@@ -151,6 +151,10 @@ int main(int argc, char *argv[])
             myappTranslator.load(QCoreApplication::applicationDirPath() + "/translations/klog_" + (QLocale::system().name())); /* Flawfinder: ignore */
         }
 
+        else if (((QLocale::system().name()).left(1)) == "C") /* Flawfinder: ignore */
+        { // If language is C, it will execute without showing message
+
+        }
         else if (((QLocale::system().name()).left(2)) == "en") /* Flawfinder: ignore */
         { // If language is English, it will execute without showing message
 
