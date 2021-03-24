--- setup.py.orig	2020-03-06 21:07:18 UTC
+++ setup.py
@@ -158,8 +158,5 @@ else:
                       "eyeD3 = eyed3.main:_main",
                   ]
               },
-              cmdclass={
-                  "install": PipInstallCommand,
-              },
               **PKG_INFO
         )
