--- freetype/makefile.mk.orig	Fri Aug 16 17:28:36 2002
+++ freetype/makefile.mk	Sat Jan 18 13:39:03 2003
@@ -95,6 +99,8 @@
 	objs$/.libs$/libfreetype.a
 .IF "$(OS)"=="MACOSX"
 OUT2LIB+=objs$/.libs$/libfreetype.*.dylib
+.ELIF "$(OS)"=="FREEBSD"
+OUT2LIB+=objs$/.libs$/libfreetype.so.7*
 .ELSE
 OUT2LIB+=objs$/.libs$/libfreetype.so.6*
 .ENDIF          # "$(OS)"=="MACOSX"
