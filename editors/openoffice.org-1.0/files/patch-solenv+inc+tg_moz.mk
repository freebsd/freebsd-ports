--- solenv/inc/tg_moz.mk.orig	Sat Jul 20 23:57:37 2002
+++ solenv/inc/tg_moz.mk	Sat Jul 20 23:57:55 2002
@@ -36,6 +36,14 @@
 CPUCFG=_linux.cfg
 .ENDIF
 
+.IF "$(OS)"=="FREEBSD"
+CPUCFG=_freebsd.cfg
+.ENDIF
+
+.IF "$(OS)"=="NETBSD"
+CPUCFG=_netbsd.cfg
+.ENDIF
+
 .IF "$(GEN_PRCPUCFG)"!=""
 $(GEN_PRCPUCFG): $(PRJ)$/pr$/include$/md$/$(CPUCFG) 
 	@+$(COPY) $(PRJ)$/pr$/include$/md$/$(CPUCFG) $@
