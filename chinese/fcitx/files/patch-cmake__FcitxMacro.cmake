--- ./cmake/FcitxMacro.cmake.orig	2013-09-28 17:33:14.000000000 +0900
+++ ./cmake/FcitxMacro.cmake	2014-03-19 13:46:27.000000000 +0900
@@ -366,10 +366,10 @@
   add_custom_target("${target_name}" ALL)
 
   __fcitx_addon_config_file("${target_name}" "${FCITX_ADDON_CONF_SRC}"
-    "${FCITX4_ADDON_CONFIG_INSTALL_DIR}")
+    "${FCITX4_ADDON_CONFIG_INSTALL_DESTDIR}")
   foreach(im_config ${FCITX_ADDON_IM_CONFIG})
     __fcitx_addon_config_file("${target_name}" "${im_config}"
-      "${FCITX4_INPUTMETHOD_CONFIG_INSTALL_DIR}")
+      "${FCITX4_INPUTMETHOD_CONFIG_INSTALL_DESTDIR}")
   endforeach()
   __fcitx_add_addon_lib("${FCITX_ADDON_LIB_NAME}" ${FCITX_ADDON_SOURCES})
   if(FCITX_ADDON_LINK_LIBS)
@@ -393,7 +393,7 @@
   set_target_properties("${lib_name}" PROPERTIES PREFIX ""
     COMPILE_FLAGS "-fvisibility=hidden")
   add_dependencies("${lib_name}" fcitx-scan-addons.target)
-  install(TARGETS "${lib_name}" DESTINATION "${FCITX4_ADDON_INSTALL_DIR}")
+  install(TARGETS "${lib_name}" DESTINATION "${FCITX4_ADDON_INSTALL_DESTDIR}")
 endfunction()
 
 function(__fcitx_install_addon_desc target_name)
@@ -402,7 +402,7 @@
   add_custom_target("${desc_target}" DEPENDS ${descs})
   add_dependencies("${target_name}" "${desc_target}")
   install(FILES ${descs}
-    DESTINATION "${FCITX4_CONFIGDESC_INSTALL_DIR}")
+    DESTINATION "${FCITX4_CONFIGDESC_INSTALL_DESTDIR}")
 endfunction()
 
 # Add additional config-desc files, the file will be added to extracte
@@ -893,7 +893,7 @@
   __FCITX_CONF_FILE_GET_UNIQUE_TARGET_NAME(fcitx_addon_conf targetname)
   add_custom_target(${targetname} ALL DEPENDS ${conffilename})
   install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${conffilename}"
-    DESTINATION "${FCITX4_ADDON_CONFIG_INSTALL_DIR}")
+    DESTINATION "${FCITX4_ADDON_CONFIG_INSTALL_DESTDIR}")
 ENDMACRO(FCITX_ADD_ADDON_CONF_FILE conffilename)
 
 MACRO(FCITX_ADD_INPUTMETHOD_CONF_FILE conffilename)
@@ -902,7 +902,7 @@
   __FCITX_CONF_FILE_GET_UNIQUE_TARGET_NAME(fcitx_inputmethod_conf targetname)
   add_custom_target(${targetname} ALL DEPENDS ${conffilename})
   install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${conffilename}"
-    DESTINATION "${FCITX4_INPUTMETHOD_CONFIG_INSTALL_DIR}")
+    DESTINATION "${FCITX4_INPUTMETHOD_CONFIG_INSTALL_DESTDIR}")
 ENDMACRO()
 
 MACRO(FCITX_ADD_CONFIGDESC_FILE)
