--- ../freetype/makefile.mk.orig	Tue Feb 26 12:21:37 2002
+++ ../freetype/makefile.mk	Thu Aug  1 00:51:46 2002
@@ -79,7 +79,11 @@
 #relative to CONFIGURE_DIR
 CONFIGURE_ACTION=$(GNUMAKE)
 .IF "$(GUI)"=="UNX"
-CONFIGURE_FLAGS=setup
+.IF "$(debug)"==""
+CONFIGURE_FLAGS=setup CFLAGS="-O"
+.ELSE			# "$(debug)"==""
+CONFIGURE_FLAGS=setup CFLAGS="-O -g -ggdb"
+.ENDIF			# "$(debug)"==""
 .ELSE			# "$(GUI)"=="UNX"
 CONFIGURE_FLAGS=setup visualc
 .ENDIF			# "$(GUI)"=="UNX"
@@ -90,7 +94,7 @@
 .IF "$(GUI)"=="UNX"
 OUT2LIB= \
 	objs$/.libs$/libfreetype.a \
-	objs$/.libs$/libfreetype.so.6*
+	objs$/.libs$/libfreetype.so.7
 	
 .ENDIF			# "$(GUI)"=="UNX"
 
