--- setup.py.orig	2008-12-29 02:17:48.000000000 +0100
+++ setup.py	2014-10-01 17:39:30.470196570 +0200
@@ -33,17 +33,18 @@
 
 api_extension = Extension("plutocracy.api", ["src/plutocracy-lib.c",
                           "src/plutocracy.c"] + plutocracy_src,
-                          include_dirs=[".", "/usr/include/SDL",
-                                        "/usr/include/pango-1.0",
-                                        "/usr/include/glib-2.0",
-                                        "/usr/lib/glib-2.0/include"],
+                          include_dirs=[".", "/usr/local/include/SDL",
+                                        "/usr/local/include/pango-1.0",
+                                        "/usr/local/include/glib-2.0",
+                                        "/usr/local/lib/glib-2.0/include",
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
