--- solenv/inc/tg_shl.mk.orig	Tue Jan  7 16:22:13 2003
+++ solenv/inc/tg_shl.mk	Sat Jan 18 12:51:58 2003
@@ -319,7 +319,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			${CC} -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CXX) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
