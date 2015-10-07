--- cmake/Modules/GrBoost.cmake.orig	2015-05-12 09:39:44 UTC
+++ cmake/Modules/GrBoost.cmake
@@ -53,6 +53,8 @@ if(MSVC)
 endif(MSVC)
 
 find_package(Boost "1.35" COMPONENTS ${BOOST_REQUIRED_COMPONENTS})
+message(status "Boost_FOUND = ${Boost_FOUND})
+message(status "Boost_LIBRARIES = ${Boost_LIBRARIES})
 
 # This does not allow us to disable specific versions. It is used
 # internally by cmake to know the formation newer versions. As newer
