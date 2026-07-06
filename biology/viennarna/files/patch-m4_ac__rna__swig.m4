--- m4/ac_rna_swig.m4.orig	2026-04-14 04:46:13 UTC
+++ m4/ac_rna_swig.m4
@@ -18,7 +18,6 @@ AC_DEFUN([RNA_ENABLE_SWIG_INTERFACES],[
 
   AM_CONDITIONAL(HAS_SWIG, test "x$has_swig" != "xno")
   RNA_ENABLE_SWIG_PERL
-  RNA_ENABLE_SWIG_PYTHON2
   RNA_ENABLE_SWIG_PYTHON
 
 ])
@@ -130,54 +129,5 @@ AC_DEFUN([RNA_ENABLE_SWIG_PYTHON],[
     AC_CONFIG_FILES([interfaces/Python/Makefile interfaces/Python/version.i])
     AC_CONFIG_FILES([interfaces/Python/RNA/__init__.py])
     AC_CONFIG_FILES([setup.py setup.cfg pyproject.toml])
-  ])
-])
-
-AC_DEFUN([RNA_ENABLE_SWIG_PYTHON2],[
-
-  AX_REQUIRE_DEFINED([AX_PYTHON2_DEVEL])
-
-  RNA_ADD_PACKAGE([python2],
-                  [Python2 interface],
-                  [no],[],[],
-                  [${srcdir}/interfaces/Python2/Makefile.am])
-
-
-  ## check for python2 requirements
-  AS_IF([test "x$with_python2" != "xno"],[
-    AS_IF([test "x$wants_swig" = "xno"],[
-      with_python2="no"
-    ],[
-      ## if swig is not available, check whether we already have swig generated sources
-      if test "x$has_swig" != "xyes"
-      then
-        AC_RNA_TEST_FILE([${srcdir}/interfaces/Python2/RNA_wrap.cpp],[],[
-          with_python2="no"
-        ])
-        AC_RNA_TEST_FILE([${srcdir}/interfaces/Python2/RNA.py],[],[
-          with_python2="no"
-        ])
-      fi
-    ])
-  ])
-
-  AS_IF([test "x$with_python2" != "xno"],[
-
-    ## check for python2 config
-    AX_PYTHON2_DEVEL
-
-    if test "x$python2_enabled_but_failed" != "x"
-    then
-      with_python2="no"
-    else
-      AC_SUBST(PYTHON2DIR,$python2dir)
-      AC_SUBST(PKGPYTHON2DIR,$pkgpython2dir)
-      AC_SUBST(PYEXEC2DIR,$py2execdir)
-      AC_SUBST(PKGPYEXEC2DIR,$pkgpy2execdir)
-
-      AC_DEFINE([WITH_PYTHON2_INTERFACE], [1], [Create the Python 2.x interface to RNAlib])
-      AC_SUBST([PYTHON2_INTERFACE], [Python2])
-      AC_CONFIG_FILES([interfaces/Python2/Makefile interfaces/Python2/version.i])
-    fi
   ])
 ])
