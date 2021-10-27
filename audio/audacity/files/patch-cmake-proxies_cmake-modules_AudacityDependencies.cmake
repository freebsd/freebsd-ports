--- cmake-proxies/cmake-modules/AudacityDependencies.cmake.orig	2021-08-27 22:30:37 UTC
+++ cmake-proxies/cmake-modules/AudacityDependencies.cmake
@@ -1,11 +1,14 @@
 # Load Conan
-include( conan )
 
-conan_add_remote(NAME audacity
-    URL https://artifactory.audacityteam.org/artifactory/api/conan/conan-local
-    VERIFY_SSL True
-)
+if( ${_OPT}conan_enabled )
+    include( conan )
 
+    conan_add_remote(NAME audacity
+        URL https://artifactory.audacityteam.org/artifactory/api/conan/conan-local
+        VERIFY_SSL True
+    )
+endif()
+
 set( CONAN_BUILD_REQUIRES )
 set( CONAN_REQUIRES )
 set( CONAN_PACKAGE_OPTIONS )
@@ -13,24 +16,30 @@ set( CONAN_ONLY_DEBUG_RELEASE )
 set( CONAN_CONFIG_OPTIONS )
 set( CONAN_RESOLVE_LIST )
 
-# Add a Conan dependency
-# Example usage:
-# add_conan_lib( 
-#   wxWdidget 
-#   wxwidgets/3.1.3-audacity
-#   OPTION_NAME wxwidgets
-#   SYMBOL WXWIDGET
-#   REQUIRED 
-#   ALWAYS_ALLOW_CONAN_FALLBACK
-#   PKG_CONFIG "wxwidgets >= 3.1.3"
-#   FIND_PACKAGE_OPTIONS COMPONENTS adv base core html qa xml
-#   INTERFACE_NAME wxwidgets::wxwidgets
-#   HAS_ONLY_DEBUG_RELEASE
-#   CONAN_OPTIONS 
-#        wxwidgets:shared=True
-# )
+#[[
+Add a Conan dependency
 
+Example usage:
 
+add_conan_lib( 
+  wxWdidget 
+  wxwidgets/3.1.3-audacity
+  OPTION_NAME wxwidgets
+  SYMBOL WXWIDGET
+  REQUIRED 
+  ALWAYS_ALLOW_CONAN_FALLBACK
+  PKG_CONFIG "wxwidgets >= 3.1.3"
+  FIND_PACKAGE_OPTIONS COMPONENTS adv base core html qa xml
+  INTERFACE_NAME wxwidgets::wxwidgets
+  HAS_ONLY_DEBUG_RELEASE
+  CONAN_OPTIONS 
+       wxwidgets:shared=True
+)
+
+PKG_CONFIG accepts a list of possible package configurations. 
+add_conan_lib will iterate over it one by one until the library is found.
+]]
+
 function (add_conan_lib package conan_package_name )
     # Extract the list of packages from the function args
     list( SUBLIST ARGV 2 -1 options )
@@ -54,6 +63,8 @@ function (add_conan_lib package conan_package_name )
             set( list_mode on )
             set( allow_find_package on )
             set( current_var "find_package_options" )
+        elseif ( opt STREQUAL "ALLOW_FIND_PACKAGE" )
+            set ( allow_find_package on )
         elseif ( opt STREQUAL "CONAN_OPTIONS" )
             set( list_mode on )
             set( current_var "conan_package_options" )
@@ -93,14 +104,23 @@ function (add_conan_lib package conan_package_name )
 
     set( option_desc "local" )
 
-    if( pkg_config_options OR allow_find_package )
+    if( pkg_config_options OR allow_find_package OR NOT ${_OPT}conan_enabled )
         set( sysopt "system" )
         string( PREPEND option_desc "system (if available), " )
-        set( default "${${_OPT}lib_preference}" )
+
+        if( ${_OPT}conan_enabled )
+            set( default "${${_OPT}lib_preference}" )
+        else()
+            set( default "system" )
+        endif()
     else()
         set( default "local" )
     endif()
 
+    if( ${_OPT}conan_enabled )
+        set( localopt "local" )
+    endif()
+
     if( NOT required )
         set( reqopt "off" )
         string( APPEND option_desc ", off" )
@@ -109,7 +129,7 @@ function (add_conan_lib package conan_package_name )
     cmd_option( ${option_name}
                 "Use ${option_name_base} library [${option_desc}]"
                 "${default}"
-                STRINGS ${sysopt} "local" ${reqopt}
+                STRINGS ${sysopt} ${localopt} ${reqopt}
     )
     
     # Early bail out
@@ -129,26 +149,28 @@ function (add_conan_lib package conan_package_name )
         return()
     endif()
 
-    if( ${option_name} STREQUAL "system" )
+    if( ${option_name} STREQUAL "system" OR NOT ${_OPT}conan_enabled )
         if( pkg_config_options )
-            pkg_check_modules( PKG_${package} ${pkg_config_options} )
+            foreach(variant ${pkg_config_options})
+                pkg_check_modules( PKG_${package} ${variant} )
 
-            if( PKG_${package}_FOUND )
-                message( STATUS "Using '${package}' system library" )
-    
-                # Create the target interface library
-                add_library( ${interface_name} INTERFACE IMPORTED GLOBAL)
+                if( PKG_${package}_FOUND )
+                    message( STATUS "Using '${package}' system library" )
         
-                # Retrieve the package information
-                get_package_interface( PKG_${package} )
-        
-                # And add it to our target
-                target_include_directories( ${interface_name} INTERFACE ${INCLUDES} )
-                target_link_libraries( ${interface_name} INTERFACE ${LIBRARIES} )
+                    # Create the target interface library
+                    add_library( ${interface_name} INTERFACE IMPORTED GLOBAL)
+            
+                    # Retrieve the package information
+                    get_package_interface( PKG_${package} )
+            
+                    # And add it to our target
+                    target_include_directories( ${interface_name} INTERFACE ${INCLUDES} )
+                    target_link_libraries( ${interface_name} INTERFACE ${LIBRARIES} )
 
-                message(STATUS "Added inteface ${interface_name} ${INCLUDES} ${LIBRARIES}")
-                return()
-            endif()
+                    message(STATUS "Added inteface ${interface_name} ${INCLUDES} ${LIBRARIES}")
+                    return()
+                endif()
+            endforeach()
         endif()
 
         if( allow_find_package )
@@ -160,7 +182,7 @@ function (add_conan_lib package conan_package_name )
             endif()
         endif()
 
-        if( system_only )
+        if( system_only OR NOT ${_OPT}conan_enabled )
             message( FATAL_ERROR "Failed to find the system package ${package}" )
         else()
             set( ${option_name} "local" )
@@ -237,34 +259,36 @@ function ( _conan_install build_type )
 endfunction()
 
 macro( resolve_conan_dependencies )
-    message(STATUS 
-    "Executing Conan: \
-        REQUIRES ${CONAN_REQUIRES}
-        GENERATORS cmake_find_package_multi
-        BUILD_REQUIRES ${CONAN_BUILD_REQUIRES}
-        ${CONAN_CONFIG_OPTIONS}
-        OPTIONS ${CONAN_PACKAGE_OPTIONS}
-    ")
+    if( ${_OPT}conan_enabled )
+        message(STATUS 
+        "Executing Conan: \
+            REQUIRES ${CONAN_REQUIRES}
+            GENERATORS cmake_find_package_multi
+            BUILD_REQUIRES ${CONAN_BUILD_REQUIRES}
+            ${CONAN_CONFIG_OPTIONS}
+            OPTIONS ${CONAN_PACKAGE_OPTIONS}
+        ")
 
-    if(MSVC OR XCODE)
-        foreach(TYPE ${CMAKE_CONFIGURATION_TYPES})
-            _conan_install(${TYPE})
-        endforeach()
-    else()
-        _conan_install(${CMAKE_BUILD_TYPE})
-    endif()
+        if(MSVC OR XCODE)
+            foreach(TYPE ${CMAKE_CONFIGURATION_TYPES})
+                _conan_install(${TYPE})
+            endforeach()
+        else()
+            _conan_install(${CMAKE_BUILD_TYPE})
+        endif()
 
-    list( REMOVE_DUPLICATES CONAN_REQUIRES )
+        list( REMOVE_DUPLICATES CONAN_REQUIRES )
 
-    foreach( package ${CONAN_RESOLVE_LIST} )
-        message(STATUS "Resolving Conan library ${package}")
+        foreach( package ${CONAN_RESOLVE_LIST} )
+            message(STATUS "Resolving Conan library ${package}")
 
-        find_package(${package} CONFIG)
+            find_package(${package} CONFIG)
 
-        if (NOT ${package}_FOUND)
-            message( FATAL_ERROR "Failed to find the conan package ${package}" )
-        endif()
-    endforeach()
+            if (NOT ${package}_FOUND)
+                message( FATAL_ERROR "Failed to find the conan package ${package}" )
+            endif()
+        endforeach()
+    endif()
 
     file(GLOB dependency_helpers "${AUDACITY_MODULE_PATH}/dependencies/*.cmake")
 
