- correct the path of the test executables

--- cmake/Utils.cmake.orig	2023-12-16 02:01:44 UTC
+++ cmake/Utils.cmake
@@ -41,7 +41,7 @@ macro(add_kaldi_test_executable)
             COMMAND ${kaldi_test_exe_NAME}
             WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
         # list(APPEND KALDI_TEST_EXECUTABLES ${kaldi_test_exe_NAME})
-        install(TARGETS ${kaldi_test_exe_NAME} RUNTIME DESTINATION testbin)
+        install(TARGETS ${kaldi_test_exe_NAME} RUNTIME DESTINATION share/kaldi/testbin)
 
         unset(kaldi_test_exe_NAME)
         unset(kaldi_test_exe_SOURCES)
