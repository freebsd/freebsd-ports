--- tools/json_schema_compiler/feature_compiler.py.orig	2021-01-07 00:37:24 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -243,6 +243,7 @@ FEATURE_GRAMMAR = ({
                 'chromeos': 'Feature::CHROMEOS_PLATFORM',
                 'lacros': 'Feature::LACROS_PLATFORM',
                 'linux': 'Feature::LINUX_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
             }
