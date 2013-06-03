--- plugins/input/python/build.py.orig 2013-06-02 20:28:29.000000000 +0400
+++ plugins/input/python/build.py 2013-06-02 20:29:34.000000000 +0400
@@ -68,6 +68,9 @@
 LINKFLAGS=linkflags
 )

+# if the plugin links to libmapnik ensure it is built first
+Depends(TARGET, env.subst('../../../src/%s' % env['MAPNIK_LIB_NAME']))
+
 # if 'uninstall' is not passed on the command line
 # then we actually create the install targets that
 # scons will install if 'install' is passed as an arg
