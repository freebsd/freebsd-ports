Issuetracker : #i56951#
CWS          : N/A
Author       : <maho@openoffice.org> (JCA)
Description  : FreeBSD porting : javavendors_linux.xml can be used for FreeBSD as well.
javavendors_linux.xml can be used for FreeBSD as well.

--- jvmfwk/distributions/OpenOfficeorg/makefile.mk	Thu Sep  8 04:26:17 2005
+++ jvmfwk/distributions/OpenOfficeorg/makefile.mk	Sat Oct 22 18:31:16 2005
@@ -49,7 +49,7 @@
 .IF "$(GUI)"=="UNX"
 .IF "$(OS)"=="MACOSX"
 	+-$(COPY) javavendors_macosx.xml $(BIN)$/javavendors_ooo.xml
-.ELIF "$(OS)"=="LINUX"
+.ELIF "$(OS)"=="LINUX" || "$(OS)"=="FREEBSD"
 	+-$(COPY) javavendors_linux.xml $(BIN)$/javavendors_ooo.xml
 .ELSE
 	+-$(COPY) javavendors_unx.xml $(BIN)$/javavendors_ooo.xml
