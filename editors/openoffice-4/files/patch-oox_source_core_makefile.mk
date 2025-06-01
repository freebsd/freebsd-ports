--- oox/source/core/makefile.mk.orig	2021-04-02 12:58:21 UTC
+++ oox/source/core/makefile.mk
@@ -35,7 +35,7 @@ ENABLE_EXCEPTIONS=TRUE
 .INCLUDE: $(PRJ)$/util$/makefile.pmk
 
 .IF "$(SYSTEM_OPENSSL)" == "YES"
-CFLAGS+= $(OPENSSL_CFLAGS)
+INCSYSTEM+= $(OPENSSL_CFLAGS)
 .ENDIF
 
 # --- Files --------------------------------------------------------
