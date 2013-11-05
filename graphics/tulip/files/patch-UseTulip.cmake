CMake 2.8.12 fix.

http://cmake.org/gitweb?p=cmake.git;a=commitdiff;h=9ce60ff509c4ff27fe861fc5b2080f50897a68c4
changed the arguments of the internal macros QT4_EXTRACT_OPTIONS and
QT4_CREATE_MOC_COMMAND which the port uses directly, so we have to adapt.

Tulip 4.x should not have this problem, as it removed its QT4_* macro wrappers.
--- UseTulip.cmake.orig	2012-06-11 10:46:14.000000000 +0300
+++ UseTulip.cmake	2013-11-03 19:16:59.000000000 +0200
@@ -1,5 +1,5 @@
 MACRO (TULIP_QT4_WRAP_UI outfiles )
-  QT4_EXTRACT_OPTIONS(ui_files ui_options ${ARGN})
+  QT4_EXTRACT_OPTIONS(ui_files ui_options ui_target ${ARGN})
   FOREACH (it ${ui_files})
     GET_FILENAME_COMPONENT(outfile ${it} NAME_WE)
     GET_FILENAME_COMPONENT(infile ${it} ABSOLUTE)
@@ -13,7 +13,7 @@
 ENDMACRO (TULIP_QT4_WRAP_UI)
 
 MACRO (TULIP_QT4_WRAP_UI_IN_INCLUDE outfiles )
-  QT4_EXTRACT_OPTIONS(ui_files ui_options ${ARGN})
+  QT4_EXTRACT_OPTIONS(ui_files ui_options ui_target ${ARGN})
   FOREACH (it ${ui_files})
     GET_FILENAME_COMPONENT(outfile ${it} NAME_WE)
     GET_FILENAME_COMPONENT(infile ${it} ABSOLUTE)
@@ -27,7 +27,7 @@
 ENDMACRO (TULIP_QT4_WRAP_UI_IN_INCLUDE)
 
 MACRO (TULIP_QT4_WRAP_UI_IN_INCLUDE_TULIP outfiles )
-  QT4_EXTRACT_OPTIONS(ui_files ui_options ${ARGN})
+  QT4_EXTRACT_OPTIONS(ui_files ui_options ui_target ${ARGN})
   FOREACH (it ${ui_files})
     GET_FILENAME_COMPONENT(outfile ${it} NAME_WE)
     GET_FILENAME_COMPONENT(infile ${it} ABSOLUTE)
@@ -42,12 +42,12 @@
 
 MACRO (TULIP_QT4_WRAP_CPP outfiles )
   QT4_GET_MOC_FLAGS(moc_flags)
-  QT4_EXTRACT_OPTIONS(moc_files moc_options ${ARGN})
+  QT4_EXTRACT_OPTIONS(moc_files moc_options moc_target ${ARGN})
   FOREACH (it ${moc_files})
     GET_FILENAME_COMPONENT(outfile ${it} NAME_WE)
     GET_FILENAME_COMPONENT(it ${it} ABSOLUTE)
     SET(outfile ${CMAKE_CURRENT_BINARY_DIR}/moc_${outfile}.cpp)
-    QT4_CREATE_MOC_COMMAND(${it} ${outfile} "${moc_flags}" "${moc_options}")
+    QT4_CREATE_MOC_COMMAND(${it} ${outfile} "${moc_flags}" "${moc_options}" "${moc_target}")
     SET(${outfiles} ${${outfiles}} ${outfile})
   ENDFOREACH(it)
 ENDMACRO (TULIP_QT4_WRAP_CPP)	
