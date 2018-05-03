--- cmake/modules/FindVorbisFile.cmake.orig	2018-04-16 17:54:59 UTC
+++ cmake/modules/FindVorbisFile.cmake
@@ -13,53 +13,14 @@
 
 FIND_PATH(VORBISFILE_INCLUDE_DIRS
 	vorbis/vorbisfile.h
-	HINTS
-	$ENV{VORBISDIR}
-	$ENV{VORBIS_PATH}
-	PATH_SUFFIXES include
-	PATHS
-	~/Library/Frameworks
-	/Library/Frameworks
-	/usr/local
-	/usr
-	/sw # Fink
-	/opt/local # DarwinPorts
-	/opt/csw # Blastwave
-	/opt
 )
 
 FIND_LIBRARY(VORBISFILE_LIBRARIES 
 	NAMES vorbisfile
-	HINTS
-	$ENV{VORBISDIR}
-	$ENV{VORBIS_PATH}
-	PATH_SUFFIXES win32/VorbisFile_Dynamic_Release lib
-	PATHS
-	~/Library/Frameworks
-	/Library/Frameworks
-	/usr/local
-	/usr
-	/sw
-	/opt/local
-	/opt/csw
-	/opt
 )
 
 FIND_LIBRARY(VORBISFILE_LIBRARIES_DEBUG 
 	NAMES VorbisFile_d
-	HINTS
-	$ENV{VORBISDIR}
-	$ENV{VORBIS_PATH}
-	PATH_SUFFIXES win32/VorbisFile_Dynamic_Debug lib
-	PATHS
-	~/Library/Frameworks
-	/Library/Frameworks
-	/usr/local
-	/usr
-	/sw
-	/opt/local
-	/opt/csw
-	/opt
 )
 
 SET(VORBISFILE_FOUND "NO")
