--- configure.py.orig	2014-02-14 21:33:53.000000000 +0100
+++ configure.py	2014-08-20 13:42:06.162076745 +0200
@@ -228,7 +228,7 @@
                            {'src': file,
                             'dst': libexecdir}
                            for (file, dest) in install_files_bc])
-install_cmd = ' && '.join(['%(old)s && mkdir -p ${DESTDIR}/%(dst)s && cp -r %(srcdir)s/generic/include/clc ${DESTDIR}/%(dst)s' %
+install_cmd = ' && '.join(['%(old)s && mkdir -p ${DESTDIR}/%(dst)s && cp -r generic/include/clc ${DESTDIR}/%(dst)s' %
                            {'old': install_cmd,
                             'dst': includedir,
                             'srcdir': srcdir}])
