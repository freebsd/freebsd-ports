--- src/modp_b64.h.orig	Tue Sep 25 22:39:43 2007
+++ src/modp_b64.h	Tue Sep 25 22:40:03 2007
@@ -166,7 +166,7 @@
      * \param[in] s the input string to encode
      * \return a newly allocated b64 string.  Empty if failed.
      */
-    inline std::string b64_encode(const string& s)
+    inline std::string b64_encode(const std::string& s)
     {
         return b64_encode(s.data(), s.size());
     }
