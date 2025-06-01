--- sccomp/source/solver/makefile.mk.orig	2021-04-02 12:58:22 UTC
+++ sccomp/source/solver/makefile.mk
@@ -66,7 +66,8 @@ DEF1NAME=       $(SHL1TARGET)
 DEF1NAME=       $(SHL1TARGET)
 
 .IF "$(SYSTEM_COINMP)" == "YES"
-CFLAGS+= $(COINMP_CFLAGS) -DSYSTEM_COINMP
+INCSYSTEM+= $(COINMP_CFLAGS)
+CFLAGS+= -DSYSTEM_COINMP
 # Use the library flags from configure
 SHL1STDLIBS+=$(COINMP_LIBS)
 .ELSE
