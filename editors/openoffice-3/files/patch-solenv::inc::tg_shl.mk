--- ../solenv/inc/tg_shl.mk.orig	Fri Aug 16 13:26:42 2002
+++ ../solenv/inc/tg_shl.mk	Sat Oct 19 10:54:46 2002
@@ -319,7 +319,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -460,22 +460,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL$(TNR)TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
