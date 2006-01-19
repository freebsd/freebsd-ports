Index: solenv/inc/packtools.mk
===================================================================
RCS file: /cvs/tools/solenv/inc/packtools.mk,v
retrieving revision 1.6
diff -u -r1.6 packtools.mk
--- solenv/inc/packtools.mk	13 Jan 2006 15:02:07 -0000	1.6
+++ solenv/inc/packtools.mk	18 Jan 2006 10:51:17 -0000
@@ -34,6 +34,8 @@
 #*************************************************************************
 
 .IF "$(GUI)"!="WNT"
+.IF "$(OS)"=="LINUX"
 RPM*:=$(shell +-ls -l `which rpm` >& /dev/null && set i=`which rpm` && echo rpm`test -x $${{i}}build && echo build`)
 DPKG*:=$(shell +-ls -l `which dpkg` >& /dev/null && echo dpkg)
 .ENDIF
+.ENDIF
