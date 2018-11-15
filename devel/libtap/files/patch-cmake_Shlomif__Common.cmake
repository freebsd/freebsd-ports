--- cmake/Shlomif_Common.cmake.orig	2018-11-15 09:55:11 UTC
+++ cmake/Shlomif_Common.cmake
@@ -76,7 +76,7 @@ MACRO(PREPROCESS_PATH_PERL_WITH_FULL_NAMES TARGET_NAME
             "--subst" "prefix=${CMAKE_INSTALL_PREFIX}"
             "--subst" "bindir=${CMAKE_INSTALL_PREFIX}/bin"
             "--subst" "libdir=${CMAKE_INSTALL_PREFIX}/${WML_LIB_DIR}"
-            "--subst" "mandir=${CMAKE_INSTALL_PREFIX}/share/man"
+            "--subst" "mandir=${CMAKE_INSTALL_PREFIX}/man"
             "--subst" "PATH_PERL=${PERL_EXECUTABLE}"
             "--subst" "INSTALLPRIVLIB=${CMAKE_INSTALL_PREFIX}/${WML_LIB_DIR}"
             "--subst" "INSTALLARCHLIB=${CMAKE_INSTALL_PREFIX}/${WML_LIB_DIR}"
@@ -182,7 +182,7 @@ MACRO(INSTALL_MAN SOURCE SECTION)
         FILES
             ${SOURCE}
         DESTINATION
-            "share/man/man${SECTION}"
+            "man/man${SECTION}"
     )
 ENDMACRO(INSTALL_MAN)
 
@@ -200,7 +200,7 @@ MACRO(INSTALL_RENAME_MAN SOURCE SECTION INSTNAME MAN_S
         FILES
             "${MAN_SOURCE_DIR}/${SOURCE}"
         DESTINATION
-            "share/man/man${SECTION}"
+            "man/man${SECTION}"
         RENAME
             "${INSTNAME}.${SECTION}"
     )
@@ -211,7 +211,7 @@ MACRO(INSTALL_CAT_MAN SOURCE SECTION)
         FILES
             "${CMAKE_CURRENT_BINARY_DIR}/${SOURCE}"
         DESTINATION
-            "share/man/cat${SECTION}"
+            "man/cat${SECTION}"
     )
 ENDMACRO(INSTALL_CAT_MAN)
 
@@ -295,7 +295,7 @@ MACRO(INSTALL_MAN SOURCE SECTION)
         FILES
             ${SOURCE}
         DESTINATION
-            "share/man/man${SECTION}"
+            "man/man${SECTION}"
    )
 ENDMACRO(INSTALL_MAN)
 
