commit e81fa01
Author: sergiobenrocha2 <sergiobenrocha2@gmail.com>
Date:   Wed Sep 16 19:07:25 2015 -0300

    fix build when git is installed but there is no .git folder.

diff --git git-version.cmake git-version.cmake
index a507a93..ff276d7 100644
--- git-version.cmake
+++ git-version.cmake
@@ -3,7 +3,7 @@ set(GIT_VERSION "unknown")
 set(GIT_VERSION_UPDATE "1")
 
 find_package(Git)
-if(GIT_FOUND)
+if(GIT_FOUND AND EXISTS ".git")
 	execute_process(COMMAND ${GIT_EXECUTABLE} describe --always
 		WORKING_DIRECTORY ${SOURCE_DIR}
 		RESULT_VARIABLE exit_code
