--- ../crashrep/source/unx/makefile.mk.org	Tue Jul  1 08:57:23 2003
+++ ../crashrep/source/unx/makefile.mk	Tue Jul  1 08:57:30 2003
@@ -105,6 +105,10 @@
 APP1STDLIBS=$(GTKLINKFLAGS) `pkg-config $(ONLYMODLIBS) --libs gtk+-2.0` -lpng -lzlib -ljpeg -ltiff -Bdynamic -lXext -lX11 -ldl -lsocket -lnsl
 .ENDIF
 
+.IF "$(OS)" == "FREEBSD"
+APP1STDLIBS=$(GTKLINKFLAGS) `pkg-config $(ONLYMODLIBS) --libs gtk+-2.0` -lpng -lzlib -ljpeg -ltiff -Wl,-Bdynamic -lXext -lX11
+.ENDIF
+
 ALL: ALLTAR $(BIN)$/crash_dump.res.01
 
 # --- Targets ------------------------------------------------------
