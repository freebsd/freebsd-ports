--- tools/json_schema_compiler/cpp_bundle_generator.py.orig	2025-04-22 20:15:27 UTC
+++ tools/json_schema_compiler/cpp_bundle_generator.py
@@ -140,7 +140,7 @@ class CppBundleGenerator(object):
       elif platform == Platforms.FUCHSIA:
         ifdefs.append('BUILDFLAG(IS_FUCHSIA)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
