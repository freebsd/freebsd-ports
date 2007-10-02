--- src/modp_b64w.h.orig	Tue Sep 25 22:39:48 2007
+++ src/modp_b64w.h	Tue Sep 25 22:40:18 2007
@@ -173,7 +173,7 @@
      * \param[in] s the input string to encode
      * \return a newly allocated b64w string.  Empty if failed.
      */
-    inline std::string b64w_encode(const string& s)
+    inline std::string b64w_encode(const std::string& s)
     {
         return b64w_encode(s.data(), s.size());
     }
