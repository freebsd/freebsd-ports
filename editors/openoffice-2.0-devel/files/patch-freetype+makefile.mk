--- ../freetype/makefile.mk.orig	Fri Aug 16 17:28:36 2002
+++ ../freetype/makefile.mk	Fri Oct 18 20:06:42 2002
@@ -95,9 +95,11 @@
 	objs$/.libs$/libfreetype.a
 .IF "$(OS)"=="MACOSX"
 OUT2LIB+=objs$/.libs$/libfreetype.*.dylib
+.ELIF "$(OS)"=="FREEBSD"
+OUT2LIB+=objs$/.libs$/libfreetype.so.7*
 .ELSE
 OUT2LIB+=objs$/.libs$/libfreetype.so.6*
-.ENDIF          # "$(OS)"=="MACOSX"
+.ENDIF          # "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 
 .ELSE			# "$(GUI)"=="UNX"
 .IF "$(USE_SHELL)"=="4nt"
