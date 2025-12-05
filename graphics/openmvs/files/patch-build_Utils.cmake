--- build/Utils.cmake.orig	2024-05-27 00:00:00 UTC
+++ build/Utils.cmake
@@ -442,6 +442,7 @@
 		endif()
 	endif()
 	if(CLANG AND (CMAKE_CXX_STANDARD EQUAL 11 OR CMAKE_CXX_STANDARD EQUAL 14 OR CMAKE_CXX_STANDARD EQUAL 17 OR CMAKE_CXX_STANDARD EQUAL 20))
+	set(CMAKE_CXX_STANDARD 14 CACHE STRING "C++ standard" FORCE)
 		set(CMAKE_EXE_LINKER_FLAGS "-stdlib=libc++")
 		add_extra_compiler_option(-stdlib=libc++)
 	endif()
@@ -497,6 +498,7 @@
 		add_extra_compiler_option(-Wno-int-in-bool-context)
 		add_extra_compiler_option(-Wno-deprecated-declarations)
 	  endif()
+	  add_extra_compiler_option(-Wno-missing-template-arg-list-after-template-kw)
 	  add_extra_compiler_option(-fdiagnostics-show-option)
 	  add_extra_compiler_option(-ftemplate-backtrace-limit=0)
 	  
