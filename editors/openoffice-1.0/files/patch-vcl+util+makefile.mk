--- vcl/util/makefile.mk.orig	Sun Jul 21 00:12:09 2002
+++ vcl/util/makefile.mk	Sun Jul 21 00:12:11 2002
@@ -293,9 +293,9 @@
 .ENDIF          # "$(OS)"=="MACOSX"
 .ENDIF          # "$(OS)"=="SOLARIS"
 
-.IF "$(OS)"=="LINUX" || "$(OS)"=="SOLARIS"
+.IF "$(OS)"=="LINUX" || "$(OS)"=="SOLARIS" || "$(OS)"=="FREEBSD"
 SHL1STDLIBS += -laudio
-.ENDIF          # "$(OS)"=="LINUX" || "$(OS)"=="SOLARIS"
+.ENDIF          # "$(OS)"=="LINUX" || "$(OS)"=="SOLARIS" || "$(OS)"=="FREEBSD"
 
 .ENDIF          # "$(GUI)"=="UNX"
 
