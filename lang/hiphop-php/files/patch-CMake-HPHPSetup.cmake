--- CMake/HPHPSetup.cmake.orig	2012-07-13 12:37:46.091528166 +0200
+++ CMake/HPHPSetup.cmake	2012-07-13 12:38:38.308521628 +0200
@@ -113,8 +113,8 @@
 	set(CMAKE_C_FLAGS "-no-ipo -fp-model precise -wd584 -wd1418 -wd1918 -wd383 -wd869 -wd981 -wd424 -wd1419 -wd444 -wd271 -wd2259 -wd1572 -wd1599 -wd82 -wd177 -wd593 -w")
 	set(CMAKE_CXX_FLAGS "-no-ipo -fp-model precise -wd584 -wd1418 -wd1918 -wd383 -wd869 -wd981 -wd424 -wd1419 -wd444 -wd271 -wd2259 -wd1572 -wd1599 -wd82 -wd177 -wd593 -fno-omit-frame-pointer -ftemplate-depth-60 -Wall -Woverloaded-virtual -Wno-deprecated -w1 -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names")
 else()
-	set(CMAKE_C_FLAGS "-w")
-	set(CMAKE_CXX_FLAGS "-fno-gcse -fno-omit-frame-pointer -ftemplate-depth-60 -Wall -Woverloaded-virtual -Wno-deprecated -Wno-parentheses -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names")
+	set(CMAKE_C_FLAGS "-w %%CFLAGS%%")
+	set(CMAKE_CXX_FLAGS "-fno-gcse -fno-omit-frame-pointer -ftemplate-depth-60 -Wall -Woverloaded-virtual -Wno-deprecated -Wno-parentheses -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names %%CXXFLAGS%%")
 endif()
 
 IF(CMAKE_COMPILER_IS_GNUCC)
