--- CMake/HPHPSetup.cmake.orig	2013-07-12 20:00:55.000000000 +0200
+++ CMake/HPHPSetup.cmake	2013-07-21 11:03:57.285458378 +0200
@@ -133,8 +133,8 @@
 	set(CMAKE_C_FLAGS "-no-ipo -fp-model precise -wd584 -wd1418 -wd1918 -wd383 -wd869 -wd981 -wd424 -wd1419 -wd444 -wd271 -wd2259 -wd1572 -wd1599 -wd82 -wd177 -wd593 -w")
 	set(CMAKE_CXX_FLAGS "-no-ipo -fp-model precise -wd584 -wd1418 -wd1918 -wd383 -wd869 -wd981 -wd424 -wd1419 -wd444 -wd271 -wd2259 -wd1572 -wd1599 -wd82 -wd177 -wd593 -fno-omit-frame-pointer -ftemplate-depth-120 -Wall -Woverloaded-virtual -Wno-deprecated -w1 -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names")
 else()
-	set(CMAKE_C_FLAGS "-w")
-	set(CMAKE_CXX_FLAGS "-fno-gcse -fno-omit-frame-pointer -ftemplate-depth-120 -Wall -Woverloaded-virtual -Wno-deprecated -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names -Wno-error=array-bounds -Wno-error=switch -std=gnu++0x -Werror=format-security -Wno-unused-result -Wno-sign-compare")
+	set(CMAKE_C_FLAGS "%%CFLAGS%%")
+	set(CMAKE_CXX_FLAGS "-fno-gcse -fno-omit-frame-pointer -ftemplate-depth-120 -Wall -Woverloaded-virtual -Wno-deprecated -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names -Wno-error=array-bounds -Wno-error=switch -std=gnu++0x -Werror=format-security -Wno-unused-result -Wno-sign-compare %%CXXFLAGS%%")
 endif()
 
 IF(CMAKE_COMPILER_IS_GNUCC)
