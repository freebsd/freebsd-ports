--- ../freetype/makefile.mk.orig	Tue Mar  5 15:43:54 2002
+++ ../freetype/makefile.mk	Tue Mar  5 15:43:56 2002
@@ -90,7 +90,7 @@
 .IF "$(GUI)"=="UNX"
 OUT2LIB= \
 	objs$/.libs$/libfreetype.a \
-	objs$/.libs$/libfreetype.so.6*
+	objs$/.libs$/libfreetype.so.7
 	
 .ENDIF			# "$(GUI)"=="UNX"
 
