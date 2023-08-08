--- tools/json_schema_compiler/feature_compiler.py.orig	2023-03-30 00:34:17 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -271,6 +271,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
