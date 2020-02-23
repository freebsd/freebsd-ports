--- cmake/Txt2Tags.cmake.orig	2019-08-16 12:03:55 UTC
+++ cmake/Txt2Tags.cmake
@@ -42,7 +42,7 @@ MACRO(ADD_TXT2TAGS_FILES _sources)
     ADD_CUSTOM_COMMAND(
       OUTPUT ${_out}
       COMMAND ${TXT2TAGS_EXECUTABLE}
-      ARGS --encoding=utf-8 -o${_out} -t txt ${_in}
+      ARGS -o${_out} -t txt ${_in}
       DEPENDS ${_in}
       COMMENT "Building ${_out} from ${_in}"
       )
@@ -50,7 +50,7 @@ MACRO(ADD_TXT2TAGS_FILES _sources)
     ADD_CUSTOM_COMMAND(
       OUTPUT ${_out}.html
       COMMAND ${TXT2TAGS_EXECUTABLE}
-      ARGS --encoding=utf-8 -o${_out}.html -t html ${_in}
+      ARGS -o${_out}.html -t html ${_in}
       DEPENDS ${_in}
       COMMENT "Building ${_out}.html from ${_in}"
       )
