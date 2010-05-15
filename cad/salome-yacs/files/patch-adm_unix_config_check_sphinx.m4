--- adm/unix/config_files/check_sphinx.m4.orig	2010-05-05 09:45:31.000000000 +0700
+++ adm/unix/config_files/check_sphinx.m4	2010-05-05 09:46:03.000000000 +0700
@@ -20,33 +20,7 @@
 
 AC_CHECKING(for sphinx doc generator)
 
-sphinx_ok=yes
-dnl where is sphinx ?
-AC_PATH_PROG(SPHINX,sphinx-build) 
-if test "x$SPHINX" = "x"
-then
-  AC_MSG_WARN(sphinx not found)
-  sphinx_ok=no
-fi
-
-dnl Can I load ths sphinx module ?
-dnl This code comes from the ax_python_module macro.
-if test -z $PYTHON;
-then
-   PYTHON="python"
-fi
-PYTHON_NAME=`basename $PYTHON`
-AC_MSG_CHECKING($PYTHON_NAME module: sphinx)
-   $PYTHON -c "import sphinx" 2>/dev/null
-   if test $? -eq 0;
-   then
-     AC_MSG_RESULT(yes)
-     eval AS_TR_CPP(HAVE_PYMOD_sphinx)=yes
-   else
-     AC_MSG_RESULT(no)
-     eval AS_TR_CPP(HAVE_PYMOD_sphinx)=no
-     sphinx_ok=no
-   fi
+sphinx_ok=no
 
 AM_CONDITIONAL(SPHINX_IS_OK, [test x"$sphinx_ok" = xyes])
 
