--- ../connectivity/source/drivers/mozab/mozillasrc/makefile.mk.orig	Fri Mar 15 19:10:28 2002
+++ ../connectivity/source/drivers/mozab/mozillasrc/makefile.mk	Fri Mar 15 19:11:45 2002
@@ -152,6 +152,10 @@
             -Wno-long-long -pthread 
 CDEFS     += -DTRACING
 .ENDIF
+.IF "$(OS)" == "FREEBSD"
+CFLAGSCXX += \
+            -fno-rtti
+.ENDIF
 .ENDIF
 
 SHL1TARGET_NAME=$(TARGET)$(MOZAB_MAJOR)
