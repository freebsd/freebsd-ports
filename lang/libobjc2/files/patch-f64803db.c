diff --git a/CMakeLists.txt b/CMakeLists.txt
index e2746e9..80b7dfe 100644
--- CMakeLists.txt
+++ CMakeLists.txt
@@ -317,7 +317,7 @@ if (ENABLE_OBJCXX)
 			endif()
 		endif ()
 		add_custom_command(OUTPUT eh_trampoline.s
-			COMMAND ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_FLAGS} -fPIC -S "${CMAKE_SOURCE_DIR}/eh_trampoline.cc" -o - -fexceptions -fno-inline | sed "s/__gxx_personality_v0/test_eh_personality/g" > "${CMAKE_BINARY_DIR}/eh_trampoline.s"
+			COMMAND ${CMAKE_CXX_COMPILER} -fPIC -S "${CMAKE_SOURCE_DIR}/eh_trampoline.cc" -o - -fexceptions -fno-inline | sed "s/__gxx_personality_v0/test_eh_personality/g" > "${CMAKE_BINARY_DIR}/eh_trampoline.s"
 			MAIN_DEPENDENCY eh_trampoline.cc)
 		list(APPEND libobjc_ASM_SRCS eh_trampoline.s)
 		list(APPEND libobjc_CXX_SRCS objcxx_eh.cc)
