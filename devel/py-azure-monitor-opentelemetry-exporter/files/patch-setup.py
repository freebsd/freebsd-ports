--- setup.py.orig	2026-04-06 20:20:51 UTC
+++ setup.py
@@ -87,8 +87,8 @@ setup(
         "azure-core<2.0.0,>=1.28.0",
         "azure-identity~=1.17",
         "msrest>=0.6.10",
-        "opentelemetry-api==1.40",
-        "opentelemetry-sdk==1.40",
+        "opentelemetry-api>=1.40",
+        "opentelemetry-sdk>=1.40",
         "psutil>=5.9,<8",
     ],
     entry_points={
