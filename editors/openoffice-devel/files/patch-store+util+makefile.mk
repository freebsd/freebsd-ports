--- ../store/util/makefile.mk.orig	Tue Mar 11 14:58:53 2003
+++ ../store/util/makefile.mk	Tue Mar 11 14:59:34 2003
@@ -102,7 +102,11 @@
 
 # On gcc3 __Unwind_SetIP is not in supc++ but in libgcc_s.so
 .IF "$(COMID)"=="gcc3"
+.IF "$(OS)"=="FREEBSD"
+SHL1STDLIBS+= 	-lsupc++
+.ELSE
 SHL1STDLIBS+= 	-lsupc++ -lgcc_s
+.ENDIF
 .ENDIF
 
 
