--- setup.py.orig	2021-07-30 20:23:43 UTC
+++ setup.py
@@ -30,5 +30,5 @@ setup(
             "use_calver = calver.integration:version",
         ],
     },
-    use_calver=True,
+    version='%%PORTVERSION%%',
 )
