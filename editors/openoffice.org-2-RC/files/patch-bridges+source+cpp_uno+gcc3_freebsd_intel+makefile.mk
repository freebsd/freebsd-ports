Issutracker : #iXXXXX#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : catch up recent version of cpp_uno

--- bridges/source/cpp_uno/gcc3_freebsd_intel.old/makefile.mk	Fri May 20 11:14:36 2005
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/makefile.mk	Fri May 20 11:16:09 2005
@@ -87,7 +87,8 @@
 SLOFILES= \
 	$(SLO)$/except.obj		\
 	$(SLO)$/cpp2uno.obj		\
-	$(SLO)$/uno2cpp.obj
+    $(SLO)$/uno2cpp.obj \
+    $(SLO)$/call.obj
 
 SHL1TARGET= $(TARGET)
 
@@ -108,3 +109,6 @@
 
 .INCLUDE :  target.mk
 
+$(SLO)$/%.obj: %.s
+    $(CC) -c -o $(SLO)$/$(@:b).o $<
+    touch $@
