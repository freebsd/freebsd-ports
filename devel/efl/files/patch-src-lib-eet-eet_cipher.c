diff --git a/src/lib/eet/eet_cipher.c b/src/lib/eet/eet_cipher.c
index bb85452..9bff406 100644
--- src/lib/eet/eet_cipher.c.orig
+++ src/lib/eet/eet_cipher.c
@@ -236,9 +236,9 @@ on_error:
 
 # endif /* ifdef HAVE_GNUTLS */
 #else
-   void (certificate_file);
-   void (private_key_file);
-   void (cb);
+   certificate_file = NULL;
+   private_key_file = NULL;
+   cb = NULL;
 #endif /* ifdef HAVE_SIGNATURE */
    return NULL;
 }
