--- ../freetype/makefile.mk.orig	Tue Mar 11 14:13:25 2003
+++ ../freetype/makefile.mk	Tue Mar 11 14:13:27 2003
@@ -100,7 +100,7 @@
 .IF "$(OS)"=="MACOSX"
 OUT2LIB+=objs$/.libs$/libfreetype.*.dylib
 .ELIF "$(OS)"=="FREEBSD"
-OUT2LIB+=objs$/.libs$/libfreetype.so.7*
+OUT2LIB+=objs$/.libs$/libfreetype.so.9*
 .ELSE
 OUT2LIB+=objs$/.libs$/libfreetype.so.6*
 .ENDIF          # "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
