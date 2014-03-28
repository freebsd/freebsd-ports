--- cmake/Modules/GrBoost.cmake.orig	2014-03-06 20:24:23.000000000 -0500
+++ cmake/Modules/GrBoost.cmake	2014-03-06 20:25:07.000000000 -0500
@@ -53,6 +53,8 @@
 endif(MSVC)
 
 find_package(Boost "1.35" COMPONENTS ${BOOST_REQUIRED_COMPONENTS})
+message(status "Boost_FOUND = ${Boost_FOUND})
+message(status "Boost_LIBRARIES = ${Boost_LIBRARIES})
 
 # This does not allow us to disable specific versions. It is used
 # internally by cmake to know the formation newer versions. As newer
