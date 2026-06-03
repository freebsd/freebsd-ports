--- src/lincity-ng/Config.cpp.orig	2025-10-03 08:36:01 UTC
+++ src/lincity-ng/Config.cpp
@@ -436,11 +436,6 @@ Config::parseCommandLine(int argc, char** argv) {
 }
 
 
-template class Config::Option<int>;
-template class Config::Option<bool>;
-template class Config::Option<std::string>;
-template class Config::Option<std::filesystem::path>;
-
 template<typename T>
 Config::Option<T>::Option() :
   default_(std::nullopt)
@@ -594,5 +589,10 @@ saveOption(xmlTextWriterPtr xmlWriter, const std::stri
     xmlTextWriterWriteElement(xmlWriter, (xmlStr)name.c_str(),
       (xmlStr)"default");
 }
+
+template class Config::Option<int>;
+template class Config::Option<bool>;
+template class Config::Option<std::string>;
+template class Config::Option<std::filesystem::path>;
 
 /** @file lincity-ng/Config.cpp */
