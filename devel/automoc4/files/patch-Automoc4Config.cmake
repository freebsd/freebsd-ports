This patch is contains the following upstream commits to silence some warnings:
	* 48f6e64d98e4aaa47f2a49faa5f3e821bc21fd6e
		Don't attempt to add dependencies which do not exist.
	* b0184fe96b1a07b57cb489eb87710dc33f070dc1
		Don't attempt to read the DEFINITIONS property.

As well as the FreeBSD specific fix from
	* r297583
		Fix automoc4 detection when its .cmake file is referenced through
  a symlink.


--- Automoc4Config.cmake.orig	2009-01-22 18:50:09 UTC
+++ Automoc4Config.cmake
@@ -49,7 +49,8 @@
 #     THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


-get_filename_component(_AUTOMOC4_CURRENT_DIR  "${CMAKE_CURRENT_LIST_FILE}" PATH)
+get_filename_component(_AUTOMOC4_CURRENT_DIR  "${CMAKE_CURRENT_LIST_FILE}" REALPATH)
+get_filename_component(_AUTOMOC4_CURRENT_DIR  "${_AUTOMOC4_CURRENT_DIR}" PATH)

 # set the automoc version number
 include(${_AUTOMOC4_CURRENT_DIR}/Automoc4Version.cmake)
@@ -114,7 +115,6 @@ macro(AUTOMOC4 _target_NAME _SRCS)
    if(_moc_files)
       set(_automoc_source "${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}_automoc.cpp")
       get_directory_property(_moc_incs INCLUDE_DIRECTORIES)
-      get_directory_property(_moc_defs DEFINITIONS)
       get_directory_property(_moc_cdefs COMPILE_DEFINITIONS)

       # configure_file replaces _moc_files, _moc_incs, _moc_cdefs and _moc_defs
@@ -176,7 +176,6 @@ macro(_ADD_AUTOMOC4_TARGET _target_NAME
       set(_automoc_source "${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}.cpp")
       set(_automoc_dotFiles "${CMAKE_CURRENT_BINARY_DIR}/${_target_NAME}.cpp.files")
       get_directory_property(_moc_incs INCLUDE_DIRECTORIES)
-      get_directory_property(_moc_defs DEFINITIONS)
       get_directory_property(_moc_cdefs COMPILE_DEFINITIONS)

       # configure_file replaces _moc_files, _moc_incs, _moc_cdefs and _moc_defs
@@ -245,5 +244,7 @@ endmacro(_AUTOMOC4_KDE4_PRE_TARGET_HANDL


 macro(_AUTOMOC4_KDE4_POST_TARGET_HANDLING _target)
-   add_dependencies(${_target} "${_target}_automoc")
+  if (TARGET "${_target}_automoc")
+    add_dependencies(${_target} "${_target}_automoc")
+  endif()
 endmacro(_AUTOMOC4_KDE4_POST_TARGET_HANDLING)
