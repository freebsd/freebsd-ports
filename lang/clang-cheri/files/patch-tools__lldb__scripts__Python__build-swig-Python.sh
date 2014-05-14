--- ./tools/lldb/scripts/Python/build-swig-Python.sh.orig	2014-05-05 20:41:29.801563675 +0000
+++ ./tools/lldb/scripts/Python/build-swig-Python.sh	2014-05-05 20:42:49.410572418 +0000
@@ -20,6 +20,8 @@
 makefile_flag=$7
 dependency_flag=$8
 
+PYTHON=${PYTHON_EXECUTABLE:-/usr/bin/env python}
+
 if [ -n "$makefile_flag" -a "$makefile_flag" = "-m" ]
 then
     MakefileCalled=1
@@ -292,7 +294,7 @@
     fi
 fi
 
-python_version=`/usr/bin/env python --version 2>&1 | sed -e 's,Python ,,' -e 's,[.][0-9],,2' -e 's,[a-z][a-z][0-9],,'`
+python_version=`${PYTHON} --version 2>&1 | sed -e 's,Python ,,' -e 's,[.][0-9],,2' -e 's,[a-z][a-z][0-9],,'`
 
 if [ $MakefileCalled -eq 0 ]
 then
@@ -300,9 +302,9 @@
 else
     if [ -n "${PYTHON_INSTALL_DIR}" ]
     then
-        framework_python_dir=`/usr/bin/env python -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False, \"${PYTHON_INSTALL_DIR}\");"`/lldb
+        framework_python_dir=`${PYTHON} -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False, \"${PYTHON_INSTALL_DIR}\");"`/lldb
     else
-        framework_python_dir=`/usr/bin/env python -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False);"`/lldb
+        framework_python_dir=`${PYTHON} -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True, False);"`/lldb
     fi
 fi
 
@@ -353,7 +355,7 @@
 current_dir=`pwd`
 if [ -f "${current_dir}/modify-python-lldb.py" ]
 then
-    /usr/bin/env python ${current_dir}/modify-python-lldb.py ${CONFIG_BUILD_DIR}
+    ${PYTHON} ${current_dir}/modify-python-lldb.py ${CONFIG_BUILD_DIR}
 fi
 
 
