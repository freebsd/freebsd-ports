--- cmake/FindReadline.cmake.orig	2024-04-30 09:37:41 UTC
+++ cmake/FindReadline.cmake
@@ -19,9 +19,11 @@ if(Readline_FOUND)
 if(Readline_FOUND)
 	set(CMAKE_REQUIRED_LIBRARIES ${READLINE_LIBRARY})
 	set(CMAKE_REQUIRED_INCLUDES ${READLINE_INCLUDE_DIR})
-	check_symbol_exists(rl_filename_completion_function
-			    "stdio.h;readline.h"
-			    HAVE_RL_COMPLETION_FUNCTION)
+	# check_symbol_exists faile for readline on FreeBSD. Bypassing
+	set(HAVE_RL_COMPLETION_FUNCTION TRUE)
+	#check_symbol_exists(rl_filename_completion_function
+	#		    "stdio.h;readline.h"
+	#		    HAVE_RL_COMPLETION_FUNCTION)
 	# If linking did not work, we might have to link
 	# explicitly against libtermcap or libncurses
 	if(NOT HAVE_RL_COMPLETION_FUNCTION)
