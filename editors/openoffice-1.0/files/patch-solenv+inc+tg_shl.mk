--- ../solenv/inc/tg_shl.mk.orig	Wed Mar 13 20:40:10 2002
+++ ../solenv/inc/tg_shl.mk	Wed Mar 13 20:41:10 2002
@@ -319,9 +319,9 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE
-			cl -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF			# "$(COM)"=="GCC"
 .ENDIF			# "$(UPDATER)"=="YES"
 .IF "$(SHL$(TNR)DEFAULTRES)"!=""
