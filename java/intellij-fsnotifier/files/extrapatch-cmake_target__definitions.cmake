FreeBSD 15+ has native inotify implementation

--- cmake/target_definitions.cmake.orig	2023-07-24 21:16:54 UTC
+++ cmake/target_definitions.cmake
@@ -19,7 +19,6 @@ foreach(_lib _type IN ZIP_LISTS LIBS TYPES)
 add_library(fsnotifier_staticlib STATIC ${HEADERS} ${SOURCES})
 foreach(_lib _type IN ZIP_LISTS LIBS TYPES)
   target_link_libraries(${_lib} PUBLIC
-      ${INOTIFY_LIBRARY_DIRS}/${CMAKE_${_type}_LIBRARY_PREFIX}${INOTIFY_LIBRARIES}${CMAKE_${_type}_LIBRARY_SUFFIX}
       Threads::Threads)
   target_include_directories(${_lib} PUBLIC ${INOTIFY_INCLUDE_DIRS})
   set_target_properties(${_lib} PROPERTIES OUTPUT_NAME fsnotifier)
