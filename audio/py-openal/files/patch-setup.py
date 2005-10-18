--- setup.py	Mon Oct 17 23:22:45 2005
+++ setup.py	Mon Oct 17 23:22:19 2005
@@ -24,10 +24,10 @@
   
   ext_modules  = [Extension("_openal",
                             ["py_openal.c"],
-                            ["/usr/include", "/usr/local/include"],
+                            ["/usr/include", "/usr/local/include", "%%PREFIX%%/include"],
                             [("HAVE_CONFIG_H", None)],
                             None,
-                            ["/usr/lib", "/usr/local/lib"],
+                            ["/usr/lib", "/usr/local/lib", "%%PREFIX%%/lib"],
                             ["openal"],
                             )
                   ]
