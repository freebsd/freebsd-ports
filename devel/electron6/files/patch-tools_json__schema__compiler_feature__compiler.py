--- tools/json_schema_compiler/feature_compiler.py.orig	2019-09-10 11:14:38 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -213,6 +213,7 @@ FEATURE_GRAMMAR = (
         'enum_map': {
           'chromeos': 'Feature::CHROMEOS_PLATFORM',
           'linux': 'Feature::LINUX_PLATFORM',
+          'bsd': 'Feature::LINUX_PLATFORM',
           'mac': 'Feature::MACOSX_PLATFORM',
           'win': 'Feature::WIN_PLATFORM',
         }
