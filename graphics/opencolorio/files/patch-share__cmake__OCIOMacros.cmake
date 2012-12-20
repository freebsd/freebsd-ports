--- ./share/cmake/OCIOMacros.cmake.orig	2012-04-18 09:38:16.000000000 +0930
+++ ./share/cmake/OCIOMacros.cmake	2012-10-08 00:20:27.666350767 +1030
@@ -294,7 +294,7 @@
 MACRO(ExtractRstCPP INFILE OUTFILE)
    add_custom_command(
       OUTPUT ${OUTFILE}
-      COMMAND ${CMAKE_SOURCE_DIR}/share/sphinx/ExtractRstFromSourceCPP.py ${INFILE} ${OUTFILE}
+      COMMAND python ${CMAKE_SOURCE_DIR}/share/sphinx/ExtractRstFromSourceCPP.py ${INFILE} ${OUTFILE}
       DEPENDS ${INFILE}
       COMMENT "Extracting reStructuredText from ${INFILE} (using old process)"
    )
@@ -303,7 +303,7 @@
 MACRO(ExtractRstSimple INFILE OUTFILE)
    add_custom_command(
       OUTPUT ${OUTFILE}
-      COMMAND ${CMAKE_SOURCE_DIR}/share/sphinx/ExtractRstFromSourceSimple.py ${INFILE} ${OUTFILE}
+      COMMAND python ${CMAKE_SOURCE_DIR}/share/sphinx/ExtractRstFromSourceSimple.py ${INFILE} ${OUTFILE}
       DEPENDS ${INFILE}
       COMMENT "Extracting reStructuredText from ${INFILE}"
    )
