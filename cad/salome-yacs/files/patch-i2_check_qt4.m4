--- adm/unix/config_files/i2_check_qt4.m4.orig	2009-12-01 20:58:20.000000000 +0600
+++ adm/unix/config_files/i2_check_qt4.m4	2010-01-30 17:52:55.000000000 +0600
@@ -217,7 +217,7 @@
     qt4_cppflags="${qt4_cppflags} -I$qt4_include_path/QtGui"
     qt4_cppflags="${qt4_cppflags} -I$qt4_include_path/Qt"
     qt4_cppflags="${qt4_cppflags} -I$qt4_include_path"
-    CPPFLAGS="${CPPFLAGS} ${qt4_cppflags}"
+    CPPFLAGS="${qt4_cppflags} ${CPPFLAGS}"
     AC_LANG_PUSH(C++)
     AC_CHECK_HEADERS([qapplication.h],
                      [qt4_header_found=yes],
@@ -373,7 +373,7 @@
   AC_MSG_NOTICE([checking whether qscintilla for qt4 headers are present])
 
   # --- we test the header file presence and usability
-  CPPFLAGS="${CPPFLAGS} ${qsci4_cppflags} ${qt4_cppflags}"
+  CPPFLAGS="${qsci4_cppflags} ${qt4_cppflags} ${CPPFLAGS}"
   AC_LANG_PUSH(C++)
   AC_CHECK_HEADERS([qsciscintilla.h],
                    [qsci4_header_found=yes],
@@ -415,7 +415,7 @@
   fi
 
   # restoring saved values
-  CPPFLAGS=$saved_CPPFLAGS
+  #CPPFLAGS=$saved_CPPFLAGS
   LDFLAGS=$saved_LDFLAGS
   LIBS=$saved_LIBS
 
