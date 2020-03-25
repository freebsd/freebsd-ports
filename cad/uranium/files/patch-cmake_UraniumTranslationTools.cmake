--- cmake/UraniumTranslationTools.cmake.orig	2020-02-18 09:32:30 UTC
+++ cmake/UraniumTranslationTools.cmake
@@ -27,6 +27,8 @@ endif()
 
 # Dynamically creates targets for each language to create a *.po-file
 MACRO(TARGETS_FOR_PO_FILES language)
+message(STATUS "MACRO TARGETS FOR PO FILES")
+message(STATUS "GETTEXT_MSGINIT_EXECUTABLE ${GETTEXT_MSGINIT_EXECUTABLE}")
     if(DEFINED GETTEXT_MSGINIT_EXECUTABLE)
         message(STATUS "Creating target i18n-create-po-${language}")
         add_custom_target(i18n-create-po-${language})
@@ -76,9 +78,11 @@ ENDMACRO()
 # TODO: Adding option to set the PROJECT_NAME externally!
 MACRO(CREATE_TRANSLATION_TARGETS)
 find_package(Gettext)
-
+message(STATUS "GETTEXT_FOUND ${GETTEXT_FOUND}")
 if(GETTEXT_FOUND)
-    # translations target will convert .po files into .mo and .qm as needed.
+message(STATUS "GETTEXT_FOUND is SET")
+SET(GETTEXT_MSGINIT_EXECUTABLE "/usr/local/bin/msginit")
+# translations target will convert .po files into .mo and .qm as needed.
     # The files are checked for a _qt suffix and if it is found, converted to
     # qm, otherwise they are converted to .po.
     if(DEFINED GETTEXT_MSGINIT_EXECUTABLE)
