--- products.py.orig	2020-10-26 15:54:27 UTC
+++ products.py
@@ -136,8 +136,8 @@ def setup_hdf5(dep, summary, **kargs):
 
       actions=(
          ('IsInstalled', { 'filename' :
-             [osp.join('__setup.installdir__', 'lib', 'libhdf5.a'),
-              osp.join('__setup.installdir__', 'include', 'hdf5.h')]
+             [osp.join('__setup.installdir__', 'lib', 'libhdf5-110.a'),
+              osp.join('__setup.installdir__', 'include/hdf5-110', 'hdf5.h')]
          } ),
          ('Extract'  , {}),
          # gcc>=4.9 not supported by configure, should not use -ansi
@@ -651,14 +651,15 @@ def setup_mumps(dep, summary, **kargs):
          ('Configure', {
             'command'   : '%(PYTHON_ALIAS)s ; CC=%(CC)s FC=%(F90)s '
                           'LIBPATH="%(HOME_SCOTCH)s/lib %(HOME_METIS)s/lib" '
-                          'INCLUDES="%(HOME_SCOTCH)s/include %(HOME_METIS)s/include" '
+                          'INCLUDES="%(HOME_HDF)s/include/hdf5-110 %(HOME_SCOTCH)s/include %(HOME_METIS)s/include" '
                           'OPTLIB_FLAGS="%(MATHLIB)s %(OTHERLIB)s" '
-                          './waf configure --maths-libs="" '
+                          './waf configure --maths-libs="" --hdf5-libs="hdf5-110"'
                           '   --prefix=%(HOME_MUMPS)s --install-tests' % cfg,
             'capturestderr' : False,
          }),
          ('Make'     , {
-            'command' : '%(PYTHON_ALIAS)s ; ./waf build --jobs=1' % cfg,
+	 # Work-around on FreeBSD: MAKE_JOBS_UNSAFE + -vvv to get full logs in setup.dbg
+            'command' : '%(PYTHON_ALIAS)s ; ./waf build -vvv --jobs=1' % cfg,
             'capturestderr' : False,
          }),
          ('Install',   {
@@ -718,7 +719,8 @@ def setup_aster(dep, summary, **kargs):
            'HOME_MED', 'HOME_HDF', 'HOME_MFRONT', 'HOME_BOOST',
            'LIBPATH_BOOST', 'LIBNAME_BOOST',
            #'HOME_GMSH', 'HOME_HOMARD', optional
-           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS', 'LDFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       set=['LIBPATH_HDF', 'LIBPATH_MED', 'LIBPATH_METIS', 'LIBPATH_SCOTCH',
            'LIBPATH_MUMPS', 'LIBPATH_MFRONT'],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
@@ -736,9 +738,9 @@ def setup_aster(dep, summary, **kargs):
    os.environ['DEVTOOLS_COMPUTER_ID'] = cfg['DEVTOOLS_COMPUTER_ID']
    if cfg['ASTER_NUMVERS'] < (15, 2):
       WAF_ENV = ""
-      WAF_CONFIGURE = ("./waf configure"
-                       " --use-config=aster_full_config"
-                       " --install-tests --prefix=%(ASTER_VERSION_DIR)s")
+      WAF_CONFIGURE = ('./waf configure'
+                       ' --use-config=aster_full_config --hdf5-libs="hdf5-110"'
+                       ' --install-tests --prefix=%(ASTER_VERSION_DIR)s')
    else:
       WAF_ENV = ". env.d/aster_full_std.sh ; "
       WAF_CONFIGURE = ("./waf configure"
