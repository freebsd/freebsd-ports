--- libexplain/buffer/errno/acl_set_file.c.orig	2013-12-08 01:47:33 UTC
+++ libexplain/buffer/errno/acl_set_file.c
@@ -195,7 +195,7 @@ explain_buffer_errno_acl_set_file_explanation(explain_
 #ifdef _PC_ACL_PATH_MAX
                 if (explain_option_dialect_specific())
                 {
-                    explain_string_buffer_printf(" (%d > %d)", num, max);
+                    explain_string_buffer_printf(sb, " (%d > %d)", num, max);
                 }
 #endif
                 break;
