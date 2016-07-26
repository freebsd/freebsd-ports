--- src/tse3/file/XML.h.orig	2005-08-23 12:37:53 UTC
+++ src/tse3/file/XML.h
@@ -153,7 +153,7 @@ namespace TSE3
                 void element(const std::string &name, const std::string &value);
                 void element(const std::string &name, const char        *value);
                 void element(const std::string &name, int                value);
-                void element(const std::string &name, unsigned int       value);
+                void element(const std::string &name, size_t             value);
                 void element(const std::string &name, bool               value);
 
                 void comment(const std::string &comment);
