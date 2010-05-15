--- salome_adm/unix/config_files/check_htmlgen.m4.orig	2010-05-04 11:56:41.000000000 +0700
+++ salome_adm/unix/config_files/check_htmlgen.m4	2010-05-04 11:58:38.000000000 +0700
@@ -23,78 +23,12 @@
 
 #AC_CHECKING(for html generators)
 
-doxygen_ok=yes
+doxygen_ok=no
 dnl were is doxygen ?
-AC_PATH_PROG(DOXYGEN,doxygen) 
-if test "x$DOXYGEN" = "x"
-then
-  AC_MSG_WARN(doxygen not found)
-  doxygen_ok=no
-fi
-if test "x$doxygen_ok" = "xyes"
-then
-  version=`$DOXYGEN --version`
-  AC_MSG_RESULT(doxygen version $version)
-  case "$version" in
-	1.4.4*)
-	  DOXYGEN_WITH_PYTHON=yes
-	  DOXYGEN_WITH_STL=no
-	  ;;
-	1.4.5*)
-	  DOXYGEN_WITH_PYTHON=yes
-	  DOXYGEN_WITH_STL=yes
-	  ;;
-	1.4.6*)
-	  DOXYGEN_WITH_PYTHON=yes
-	  DOXYGEN_WITH_STL=yes
-	  ;;
-	1.4.7*)
-	  DOXYGEN_WITH_PYTHON=yes
-	  DOXYGEN_WITH_STL=yes
-	  ;;
-	1.4.8*)
-	  DOXYGEN_WITH_PYTHON=yes
-	  DOXYGEN_WITH_STL=yes
-	  ;;
-	1.4.9*)
-	  DOXYGEN_WITH_PYTHON=yes
-	  DOXYGEN_WITH_STL=yes
-	  ;;
-	[[1-9]].[[5-9]]*)
-	  DOXYGEN_WITH_PYTHON=yes
-	  DOXYGEN_WITH_STL=yes
-	  ;;
-	*)
-	  DOXYGEN_WITH_PYTHON=no
-	  DOXYGEN_WITH_STL=no
-	  ;;
-  esac
-  AC_MSG_RESULT(doxygen with support STL    - $DOXYGEN_WITH_STL)
-  AC_MSG_RESULT(doxygen with support PYTHON - $DOXYGEN_WITH_PYTHON)
-  if test "$DOXYGEN_WITH_PYTHON" == "yes" ; then
-    DOXYGEN_PYTHON_EXTENSION="*.py"
-  else
-    DOXYGEN_PYTHON_EXTENSION=""
-  fi
-  if test "$DOXYGEN_WITH_STL" == "yes" ; then
-    DOXYGEN_SUPPORT_STL="YES"
-  else
-    DOXYGEN_SUPPORT_STL="NO"
-  fi
-  AC_SUBST(DOXYGEN_WITH_PYTHON)
-  AC_SUBST(DOXYGEN_PYTHON_EXTENSION)
-  AC_SUBST(DOXYGEN_WITH_STL)
-  AC_SUBST(DOXYGEN_SUPPORT_STL)
-fi
 dnl AC_SUBST(DOXYGEN)
 
-graphviz_ok=yes
+graphviz_ok=no
 dnl were is graphviz ?
-AC_PATH_PROG(DOT,dot) 
-if test "x$DOT" = "x" ; then
-  AC_MSG_WARN(graphviz not found)
-  graphviz_ok=no
-fi
 dnl AC_SUBST(DOT)
 
 AC_PATH_PROG(LATEX,latex) 
@@ -115,17 +49,8 @@
 fi
 AC_SUBST(PDFLATEX)
 
-rst2html_ok=yes
+rst2html_ok=no
 dnl were is rst2html ?
-AC_PATH_PROG(RST2HTML,rst2html) 
-if test "x$RST2HTML" = "x"; then
-  AC_PATH_PROG(RST2HTML,rst2html.py)
-fi
-
-if test "x$RST2HTML" = "x"; then
-  AC_MSG_WARN(rst2html not found)
-  rst2html_ok=no
-fi
 AC_SUBST(RST2HTML)
 
 AM_CONDITIONAL(RST2HTML_IS_OK, [test x"$rst2html_ok" = xyes])
