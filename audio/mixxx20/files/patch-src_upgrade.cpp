--- src/upgrade.cpp.orig	2015-12-29 16:10:41 UTC
+++ src/upgrade.cpp
@@ -43,7 +43,7 @@ Upgrade::~Upgrade() {
 
 // static 
 QString Upgrade::mixxx17HomePath() {
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__BSD__)
     return QDir::homePath().append("/").append(".mixxx/");
 #elif __WINDOWS__
     return QDir::homePath().append("/").append("Local Settings/Application Data/Mixxx/");
