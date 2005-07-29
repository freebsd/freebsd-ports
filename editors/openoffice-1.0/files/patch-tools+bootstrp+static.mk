Index: tools/bootstrp/static.mk
===================================================================
RCS file: /cvs/util/tools/bootstrp/Attic/static.mk,v
retrieving revision 1.14.6.1
diff -u -r1.14.6.1 static.mk
--- tools/bootstrp/static.mk	17 Dec 2002 15:10:48 -0000	1.14.6.1
+++ tools/bootstrp/static.mk	28 Jul 2005 11:29:46 -0000
@@ -154,10 +154,11 @@
 .IF "$(OS)"=="SOLARIS"
 STATIC_LIBS		+= -lnsl -lsocket -lposix4 -lc
 .ENDIF
-.IF "$(OS)"=="LINUX"
+.IF "$(OS)"=="LINUX" || "$(OS)"=="FREEBSD"
 STATIC_LIBS		+= -lsupc++	-lX11 -lXext 
 .ENDIF
 
+
 # -----------------------------------------------------------
 
 .ELSE
