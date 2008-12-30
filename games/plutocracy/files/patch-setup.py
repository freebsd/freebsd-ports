--- setup.py.orig	2008-12-26 22:15:17.000000000 +0300
+++ setup.py	2008-12-29 04:03:48.000000000 +0300
@@ -33,17 +33,17 @@
 
 api_extension = Extension("plutocracy.api", ["src/plutocracy-lib.c",
                           "src/plutocracy.c"] + plutocracy_src,
-                          include_dirs=[".", "/usr/include/SDL",
-                                        "/usr/include/pango-1.0",
-                                        "/usr/include/glib-2.0",
-                                        "/usr/lib/glib-2.0/include"],
+                          include_dirs=[".", "/usr/local/include/SDL",
+                                        "/usr/local/include/pango-1.0",
+                                        "/usr/local/include/glib-2.0",
+                                        "/usr/local/include"],
                    libraries = ['GL', 'GLU', 'z', 'png', "SDL_Pango",
-                                'pango-1.0'],
+                                'pango-1.0', 'SDL'],
                    define_macros=[("_REENTRANT", None),
                                   ("PACKAGE", '"%s"' % "plutocracy"),
                                   ("PACKAGE_STRING", '"%s"' % PACKAGE_STRING),
                                   ("PKGDATADIR", '"%s"' %  PKGDATADIR)],
-                   extra_link_args= ["-lSDL"],
+                   extra_link_args= ["-L/usr/local/lib"],
                    depends = headers)
 
 extensions.append( api_extension )
