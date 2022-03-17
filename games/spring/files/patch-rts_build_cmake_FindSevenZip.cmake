--- rts/build/cmake/FindSevenZip.cmake.orig	2020-12-26 12:45:43 UTC
+++ rts/build/cmake/FindSevenZip.cmake
@@ -23,7 +23,7 @@ ENDIF (SEVENZIP_BIN)
 set(progfilesx86 "ProgramFiles(x86)")
 
 find_program(SEVENZIP_BIN
-	NAMES 7z 7za
+	NAMES 7zz
 	HINTS "${MINGWDIR}" "${MINGWLIBS}/bin" "$ENV{${progfilesx86}}/7-zip" "$ENV{ProgramFiles}/7-zip" "$ENV{ProgramW6432}/7-zip"
 	PATH_SUFFIXES bin
 	DOC "7zip executable"
