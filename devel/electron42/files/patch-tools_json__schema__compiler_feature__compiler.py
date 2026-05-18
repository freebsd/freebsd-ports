--- tools/json_schema_compiler/feature_compiler.py.orig	2025-04-22 20:15:27 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -289,6 +289,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
