--- tools/json_schema_compiler/feature_compiler.py.orig	2023-02-01 18:43:50 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -268,6 +268,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
