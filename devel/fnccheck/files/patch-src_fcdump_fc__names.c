--- src/fcdump/fc_names.c.orig	2021-05-10 22:04:48 UTC
+++ src/fcdump/fc_names.c
@@ -99,7 +99,7 @@ int fc_open_bfd_file(char *name, bfd **core_bfd, int *
     switch (bfd_get_arch(*core_bfd))
     {
         case bfd_arch_vax:
-        case bfd_arch_tahoe:
+        /* case bfd_arch_tahoe: */
             *core_offset_to_code = 2;
             break;
         case bfd_arch_alpha:
