--- m4/fptools_set_haskell_platform_vars.m4.orig	2025-09-10 00:00:00 UTC
+++ m4/fptools_set_haskell_platform_vars.m4
@@ -15,7 +15,7 @@
             test -z "[$]2" || eval "[$]2=ArchPPC"
             ;;
         powerpc64)
-            test -z "[$]2" || eval "[$]2=\"ArchPPC_64 ELF_V1\""
+            test -z "[$]2" || eval "[$]2=\"ArchPPC_64 ELF_V2\""
             ;;
         powerpc64le)
             test -z "[$]2" || eval "[$]2=\"ArchPPC_64 ELF_V2\""
