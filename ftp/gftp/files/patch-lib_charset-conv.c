--- lib/charset-conv.c.orig	2008-03-04 12:18:03 UTC
+++ lib/charset-conv.c
@@ -230,7 +230,7 @@ gftp_filename_from_utf8 (gftp_request * 
 #else
 
 char *
-gftp_string_to_utf8 (gftp_request * request, const char *str, size_t dest_len)
+gftp_string_to_utf8 (gftp_request * request, const char *str, size_t *dest_len)
 {
   return (NULL);
 }
@@ -238,22 +238,22 @@ gftp_string_to_utf8 (gftp_request * requ
 
 char *
 gftp_string_from_utf8 (gftp_request * request, int force_local, const char *str,
-                       size_t dest_len)
+                       size_t *dest_len)
 {
   return (NULL);
 }
 
 
 char *
-gftp_filename_to_utf8 (gftp_request * request, const char *str, size_t dest_len)
+gftp_filename_to_utf8 (gftp_request * request, const char *str, size_t *dest_len)
 {
   return (NULL);
 }
 
 
 char *
-gftp_filename_from_utf8 (gftp_request * request, int force_local,
-                         const char *str, size_t dest_len)
+gftp_filename_from_utf8 (gftp_request * request,
+                         const char *str, size_t *dest_len)
 {
   return (NULL);
 }
