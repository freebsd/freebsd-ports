--- solenv/inc/target.mk.orig	2021-04-17 18:43:53 UTC
+++ solenv/inc/target.mk
@@ -57,9 +57,9 @@ INCLUDE:=
 INCLUDE:=
 .EXPORT : INCLUDE
 .IF "$(PRJINC)"!=""
-INCLUDE!:=-I. $(INCPRE:^"-I":s/-I-I/-I/) -I$(INCLOCAL) $(INCLOCPRJ:^"-I":s/-I-I/-I/) -I$(INCPCH) -I$(INC) -I$(INCGUI) -I$(INCCOM) $(SOLARINC) $(null,$(UNOINCLUDES) $(NULL) -I$(UNOINCLUDES)) -I$(INCEXT) -I$(PRJ)/res -I$(INCPOST)
+INCLUDE!:=-I. $(INCPRE:^"-I":s/-I-I/-I/) -I$(INCLOCAL) $(INCLOCPRJ:^"-I":s/-I-I/-I/) -I$(INCPCH) -I$(INC) -I$(INCGUI) -I$(INCCOM) $(SOLARINC) $(null,$(UNOINCLUDES) $(NULL) -I$(UNOINCLUDES)) -I$(INCEXT) -I$(PRJ)/res -I$(INCPOST) $(INCSYSTEM)
 .ELSE		# "$(PRJINC)"!=""
-INCLUDE!:=-I. $(INCPRE:^"-I":s/-I-I/-I/) -I$(INCLOCAL) -I$(INCPCH) -I$(INC) -I$(INCGUI) -I$(INCCOM) $(SOLARINC) $(null,$(UNOINCLUDES) $(NULL) -I$(UNOINCLUDES)) -I$(INCEXT) -I$(PRJ)/res -I$(INCPOST)
+INCLUDE!:=-I. $(INCPRE:^"-I":s/-I-I/-I/) -I$(INCLOCAL) -I$(INCPCH) -I$(INC) -I$(INCGUI) -I$(INCCOM) $(SOLARINC) $(null,$(UNOINCLUDES) $(NULL) -I$(UNOINCLUDES)) -I$(INCEXT) -I$(PRJ)/res -I$(INCPOST) $(INCSYSTEM)
 .ENDIF		# "$(PRJINC)"!=""
 INCLUDE_C=$(subst,/stl$(SPACECHAR),dont_use_stl$(SPACECHAR) $(INCLUDE))
 .EXPORT : LIB
