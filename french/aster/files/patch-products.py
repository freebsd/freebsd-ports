--- products.py.orig	2014-03-05 09:41:19.000000000 +0100
+++ products.py	2014-03-17 18:39:24.000000000 +0100
@@ -701,7 +701,8 @@
            'HOME_PYTHON', 'PYTHON_EXE', 'PYTHONLIB',
            'HOME_MUMPS', 'HOME_ZMAT', 'HOME_MPI', 'INCLUDE_MUMPS', 'HOME_METIS',
            'HOME_MED', 'HOME_HDF',
-           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', ],
+           'LD', 'CC', 'F90', 'CXXLIB', 'OTHERLIB', 'SYSLIB', 'CFLAGS', 'LDFLAGS',
+           'CFLAGS_DBG', 'FFLAGS', 'FFLAGS_DBG','F90FLAGS', 'F90FLAGS_DBG', 'CXXLIB', ],
       reqobj=['file:?ASTER_ROOT?/bin/as_run',
               'file:?ASTER_ROOT?/etc/codeaster/profile.sh'],
    )
