
$FreeBSD$

--- tools/lldb/scripts/Python/finish-swig-Python-LLDB.sh.orig
+++ tools/lldb/scripts/Python/finish-swig-Python-LLDB.sh
@@ -34,6 +34,9 @@
 debug_flag=$5
 makefile_flag=$6
 
+# /usr/bin/env python
+PYTHON=${PYTHON_EXECUTABLE:-/usr/bin/env python}
+
 # If we don't want Python, then just do nothing here.
 # Note, at present iOS doesn't have Python, so if you're building for iOS be sure to
 # set LLDB_DISABLE_PYTHON to 1.
@@ -55,7 +58,7 @@
 fi
 
 OS_NAME=`uname -s`
-PYTHON_VERSION=`/usr/bin/env python --version 2>&1 | sed -e 's,Python ,,' -e 's,[.][0-9],,2' -e 's,[a-z][a-z][0-9],,'`
+PYTHON_VERSION=`${PYTHON} --version 2>&1 | sed -e 's,Python ,,' -e 's,[.][0-9],,2' -e 's,[a-z][a-z][0-9],,'`
 
 
 if [ $Debug -eq 1 ]
@@ -100,9 +103,9 @@
 
     if [ -n "${PYTHON_INSTALL_DIR}" ]
     then
-        framework_python_dir=`/usr/bin/env python -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False, \"${PYTHON_INSTALL_DIR}\");"`/lldb
+        framework_python_dir=`${PYTHON} -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False, \"${PYTHON_INSTALL_DIR}\");"`/lldb
     else
-        framework_python_dir=`/usr/bin/env python -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False);"`/lldb
+        framework_python_dir=`${PYTHON} -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False);"`/lldb
     fi
 fi
 
