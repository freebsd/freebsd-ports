--- tools/json_schema_compiler/feature_compiler.py.orig	2020-05-26 08:03:34 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -219,6 +219,7 @@ FEATURE_GRAMMAR = (
         'enum_map': {
           'chromeos': 'Feature::CHROMEOS_PLATFORM',
           'linux': 'Feature::LINUX_PLATFORM',
+          'bsd': 'Feature::LINUX_PLATFORM',
           'mac': 'Feature::MACOSX_PLATFORM',
           'win': 'Feature::WIN_PLATFORM',
         }
