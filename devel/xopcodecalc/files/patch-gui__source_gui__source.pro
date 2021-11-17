--- gui_source/gui_source.pro.orig	2021-07-28 16:47:13 UTC
+++ gui_source/gui_source.pro
@@ -62,18 +62,18 @@ win32-msvc*{
     }
 }
 
-linux-g++*{
+unix {
     BITSIZE = $$system(getconf LONG_BIT)
     !contains(BITSIZE, 64) {
-        message("Linux gcc x32 build")
+        message("Unix 32-bit build")
         ASM_FILES = ../asm/gcc32.s
     } else {
-        message("Linux gcc x64 build")
+        message("Unix 64-bit build")
         ASM_FILES = ../asm/gcc64.s
     }
 
     preprocess.output = ${QMAKE_FILE_BASE}.o
-    preprocess.commands = gcc -c ${QMAKE_FILE_IN}
+    preprocess.commands = $$QMAKE_CC -c ${QMAKE_FILE_IN}
 }
 
 win32-g++*{
