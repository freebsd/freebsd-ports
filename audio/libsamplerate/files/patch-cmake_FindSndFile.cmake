--- cmake/FindSndFile.cmake.orig	2021-01-28 01:50:45 UTC
+++ cmake/FindSndFile.cmake
@@ -16,10 +16,6 @@ pkg_check_modules(PC_SndFile QUIET sndfile)
 
 set(SndFile_VERSION ${PC_SndFile_VERSION})
 
-find_package(Vorbis COMPONENTS Enc QUIET)
-find_package(FLAC QUIET)
-find_package(Opus QUIET)
-
 find_path(SndFile_INCLUDE_DIR sndfile.h
   HINTS
     ${PC_SndFile_INCLUDEDIR}
@@ -42,15 +38,14 @@ find_package_handle_standard_args(SndFile
 
 if(SndFile_FOUND)
 
-  set(SndFile_LIBRARIES ${SndFile_LIBRARY} ${Vorbis_Enc_LIBRARIES} ${FLAC_LIBRARIES} ${OPUS_LIBRARIES})
-  set(SndFile_INCLUDE_DIRS ${SndFile_INCLUDE_DIR} ${Vorbis_Enc_INCLUDE_DIRS} ${FLAC_INCLUDE_DIRS} ${OPUS_INCLUDE_DIRS})
+  set(SndFile_LIBRARIES ${SndFile_LIBRARY})
+  set(SndFile_INCLUDE_DIRS ${SndFile_INCLUDE_DIR})
   
   if(NOT TARGET SndFile::sndfile)
     add_library(SndFile::sndfile UNKNOWN IMPORTED)
     set_target_properties(SndFile::sndfile PROPERTIES
       INTERFACE_INCLUDE_DIRECTORIES "${SndFile_INCLUDE_DIR}"
-      IMPORTED_LOCATION "${SndFile_LIBRARY}"
-      INTERFACE_LINK_LIBRARIES "Vorbis::vorbisenc;Opus::opus;FLAC::FLAC")
+      IMPORTED_LOCATION "${SndFile_LIBRARY}")
   endif()
 endif()
 
