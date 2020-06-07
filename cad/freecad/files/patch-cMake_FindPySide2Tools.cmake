--- cMake/FindPySide2Tools.cmake.orig	2019-10-22 16:53:35 UTC
+++ cMake/FindPySide2Tools.cmake
@@ -42,7 +42,7 @@ MACRO(PYSIDE_WRAP_UI outfiles)
         # we follow the tool command with in-place sed.
         ADD_CUSTOM_COMMAND(OUTPUT ${outfile}
           COMMAND "${PYSIDE2UICBINARY}" "${infile}" -o "${outfile}"
-          COMMAND sed -i "/^# /d" "${outfile}"
+          COMMAND sed -i \"\" "/^# /d" "${outfile}"
           MAIN_DEPENDENCY "${infile}"
         )
     endif()
@@ -68,8 +68,8 @@ MACRO(PYSIDE_WRAP_RC outfiles)
         # pyside-rcc generates in comments at beginning, which is why
         # we follow the tool command with in-place sed.
         ADD_CUSTOM_COMMAND(OUTPUT "${outfile}"
-          COMMAND "${PYSIDE2RCCBINARY}" "${infile}" ${PY_ATTRIBUTE} -o "${outfile}"
-          COMMAND sed -i "/^# /d" "${outfile}"
+          COMMAND "${PYSIDE2RCCBINARY}" "${infile}" --no-compress --generator python -o "${outfile}"
+          COMMAND sed -i \"\" "/^# /d" "${outfile}"
           MAIN_DEPENDENCY "${infile}"
         )
     endif()
