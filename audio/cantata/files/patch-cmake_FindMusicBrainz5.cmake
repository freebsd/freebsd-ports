Fix linking when the MUSICBRAINZ option is enabled.

https://github.com/nullobsi/cantata/pull/46

--- cmake/FindMusicBrainz5.cmake.orig	2024-08-05 22:17:52 UTC
+++ cmake/FindMusicBrainz5.cmake
@@ -40,7 +40,7 @@ if(PKG_CONFIG_FOUND)
 # First use PKG-Config as a starting point.
 find_package(PkgConfig)
 if(PKG_CONFIG_FOUND)
-    pkg_check_modules(PC_MusicBrainz5 QUIET libmusicbrainz5)
+    pkg_check_modules(PC_MusicBrainz5 QUIET libmusicbrainz5cc)
 endif(PKG_CONFIG_FOUND)
 
 find_path(MusicBrainz5_INCLUDE_DIR
@@ -50,7 +50,7 @@ find_library(MusicBrainz5_LIBRARY
 )
 
 find_library(MusicBrainz5_LIBRARY
-    NAMES musicbrainz5
+    NAMES musicbrainz5cc
     PATHS ${PC_MusicBrainz5_LIBRARY_DIRS}
 )
 
@@ -83,4 +83,4 @@ mark_as_advanced(
 mark_as_advanced(
         MusicBrainz5_INCLUDE_DIR
         MusicBrainz5_LIBRARY
-)
\ No newline at end of file
+)
