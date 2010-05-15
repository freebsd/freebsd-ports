--- adm/unix/config_files/check_htmlgen.m4.orig	2009-12-01 20:58:20.000000000 +0600
+++ adm/unix/config_files/check_htmlgen.m4	2010-05-08 18:13:56.000000000 +0700
@@ -20,59 +20,10 @@
 
 AC_CHECKING(for html generators)
 
-doxygen_ok=yes
-dnl were is doxygen ?
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
-  AC_SUBST(DOXYGEN_WITH_PYTHON)
-  AC_SUBST(DOXYGEN_WITH_STL)
-fi
+doxygen_ok=no
 AM_CONDITIONAL(DOXYGEN_IS_OK, [test x"$doxygen_ok" = xyes])
-dnl AC_SUBST(DOXYGEN)
+DOXYGEN_IS_OK_TRUE=""
+DOXYGEN_IS_OK_FALSE="#"
 
 AC_SUBST(GRAPHVIZHOME)
 AC_SUBST(GRAPHVIZ_CPPFLAGS)
@@ -86,7 +37,7 @@
 
 graphviz_ok=yes
 dnl were is graphviz ?
-AC_PATH_PROG(DOT,dot) 
+AC_PATH_PROG(DOT,dot)
 if test "x$DOT" = "x" ; then
   AC_MSG_WARN(graphviz not found)
   graphviz_ok=no
@@ -99,46 +50,9 @@
   GRAPHVIZ_LDFLAGS="-L${GRAPHVIZHOME}/lib -L${GRAPHVIZHOME}/lib/graphviz"
 fi
 dnl AC_SUBST(DOT)
-CPPFLAGS_old=$CPPFLAGS
-CPPFLAGS="$CPPFLAGS $GRAPHVIZ_CPPFLAGS"
-old_graphviz="yes"
-AC_CHECK_HEADERS(dotneato.h, old_graphviz="yes", old_graphviz="no")
-if test "x$old_graphviz" = "xyes" ; then
-  GRAPHVIZ_LIBADD="-ldotneato"
-else
-  GRAPHVIZ_LIBADD="-lgvc"
-fi
-CPPFLAGS=$CPPFLAGS_old
-
-AC_PATH_PROG(LATEX,latex) 
-if test "x$LATEX" = "x" ; then
-  AC_MSG_WARN(latex not found)
-fi
-AC_SUBST(LATEX)
 
-AC_PATH_PROG(DVIPS,dvips)
-if test "x$DVIPS" = "x" ; then
-  AC_MSG_WARN(dvips not found)
-fi
-AC_SUBST(DVIPS)
-
-AC_PATH_PROG(PDFLATEX,pdflatex)
-if test "x$PDFLATEX" = "x" ; then
-  AC_MSG_WARN(pdflatex not found)
-fi
-AC_SUBST(PDFLATEX)
+rst2html_ok=no
 
-rst2html_ok=yes
-dnl were is rst2html ?
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
