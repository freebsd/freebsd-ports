--- tools/json_schema_compiler/cpp_bundle_generator.py.orig	2025-03-24 20:50:14 UTC
+++ tools/json_schema_compiler/cpp_bundle_generator.py
@@ -144,7 +144,7 @@ class CppBundleGenerator(object):
         # BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(IS_CHROMEOS_LACROS).
         ifdefs.append('BUILDFLAG(IS_CHROMEOS_LACROS)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
