--- src/tse3/file/XML.h	Tue Aug 23 08:37:53 2005
+++ src/tse3/file/XML.h	Sun Sep 11 20:29:45 2005
@@ -154,5 +154,5 @@
                 void element(const std::string &name, const char        *value);
                 void element(const std::string &name, int                value);
-                void element(const std::string &name, unsigned int       value);
+                void element(const std::string &name, size_t             value);
                 void element(const std::string &name, bool               value);
 
