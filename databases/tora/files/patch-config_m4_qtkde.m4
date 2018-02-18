The library is called libqscintilla2_qt4.so since 2.10.2.
--- config/m4/qtkde.m4.orig	2018-02-16 21:51:49 UTC
+++ config/m4/qtkde.m4
@@ -112,7 +112,7 @@ AC_DEFUN([TORA_CHECK_QSCINTILLA],
     @LIB_DCOP@ \
     @LIB_KHTML@ \
     $scin_ldflags"
-  LIBS="-lqscintilla2"
+  LIBS="-lqscintilla2_qt4"
 
   AC_LANG_PUSH(C++)
 
@@ -148,7 +148,7 @@ Or alternatively see if your OS offers a QScintilla 2 
 
   AC_DEFINE_UNQUOTED(QSCINTILLA_DLL, 1, [True if on Windows.])
   AC_SUBST(QSCINTILLA_CXXFLAGS, $scin_cflags)
-  AC_SUBST(QSCINTILLA_LDFLAGS, "$scin_ldflags -lqscintilla2")
+  AC_SUBST(QSCINTILLA_LDFLAGS, "$scin_ldflags -lqscintilla2_qt4")
   AC_MSG_RESULT(yes)
 ])
 
