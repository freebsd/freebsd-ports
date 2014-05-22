--- inc/cc++/string.h.orig	2014-04-15 15:05:21.000000000 +0200
+++ inc/cc++/string.h	2014-04-15 15:10:46.000000000 +0200
@@ -74,6 +74,9 @@
  * @author David Sugar <dyfet@ostel.com>
  * @short Generic string class.
  */
+class String;
+std::istream &getline(std::istream &is, String &str, char delim = '\n', size_t size = 0);
+
 class __EXPORT String
 {
 protected:
@@ -731,7 +734,7 @@
      * @param delim deliminator to use.
      * @param size optional size limitor.
      */
-    friend __EXPORT std::istream &getline(std::istream &is, String &str, char delim = '\n', size_t size = 0);
+    friend __EXPORT std::istream &getline(std::istream &is, String &str, char delim, size_t size);
 
     /**
      * Stream the content of our string variable directly to a C++
