Index: solenv/inc/unitools.mk
===================================================================
RCS file: /cvs/tools/solenv/inc/unitools.mk,v
retrieving revision 1.12.4.2
diff -u -r1.12.4.2 unitools.mk
--- solenv/inc/unitools.mk	7 Jan 2003 15:22:16 -0000	1.12.4.2
+++ solenv/inc/unitools.mk	4 Aug 2005 01:42:23 -0000
@@ -147,7 +147,7 @@
 GNUPATCH=gnupatch
 .ELSE			# "$(OS)"=="SOLARIS"
 AWK=awk
-GNUCOPY=cp
+GNUCOPY=%%GNUCOPY%%
 GNUPATCH=patch
 .ENDIF			# "$(OS)"=="SOLARIS"
 .IF "$(OS)"=="LINUX" || "$(OS)"=="MACOSX"
