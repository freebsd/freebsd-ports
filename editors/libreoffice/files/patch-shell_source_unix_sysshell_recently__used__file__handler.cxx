--- shell/source/unix/sysshell/recently_used_file_handler.cxx.orig	2015-08-22 06:41:35 UTC
+++ shell/source/unix/sysshell/recently_used_file_handler.cxx
@@ -91,11 +91,11 @@ namespace /* private */ {
 
         void set_timestamp(const string_t& character)
         {
-            time_t t;
+            long t;
             if (sscanf(character.c_str(), "%ld", &t) != 1)
                 timestamp_ = -1;
             else
-                timestamp_ = t;
+                timestamp_ = (time_t)t;
         }
 
         void set_is_private(SAL_UNUSED_PARAMETER const string_t& /*character*/)
