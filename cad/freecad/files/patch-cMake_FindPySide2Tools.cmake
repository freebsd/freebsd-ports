--- cMake/FindPySide2Tools.cmake.orig	2021-03-12 22:05:53 UTC
+++ cMake/FindPySide2Tools.cmake
@@ -58,7 +58,7 @@
         # we follow the tool command with in-place sed.
         ADD_CUSTOM_COMMAND(OUTPUT ${outfile}
           COMMAND "${PYSIDE2UICBINARY}" ${UICOPTIONS} "${infile}" -o "${outfile}"
-          COMMAND sed -i "/^# /d" "${outfile}"
+          COMMAND sed -i \"\" "/^# /d" "${outfile}"
           MAIN_DEPENDENCY "${infile}"
         )
     endif()
@@ -85,7 +85,7 @@
         # we follow the tool command with in-place sed.
         ADD_CUSTOM_COMMAND(OUTPUT "${outfile}"
           COMMAND "${PYSIDE2RCCBINARY}" ${RCCOPTIONS} "${infile}" ${PY_ATTRIBUTE} -o "${outfile}"
-          COMMAND sed -i "/^# /d" "${outfile}"
+          COMMAND sed -i \"\" "/^# /d" "${outfile}"
           MAIN_DEPENDENCY "${infile}"
         )
     endif()
