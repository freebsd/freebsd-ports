--- ../solenv/inc/_tg_shl.mk.orig	Fri Aug 16 13:27:02 2002
+++ ../solenv/inc/_tg_shl.mk	Sat Oct 19 10:46:46 2002
@@ -219,7 +219,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -360,22 +360,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -681,7 +681,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -822,22 +822,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -1143,7 +1143,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -1284,22 +1284,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -1605,7 +1605,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -1746,22 +1746,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -2067,7 +2067,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -2208,22 +2208,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -2529,7 +2529,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -2670,22 +2670,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -2991,7 +2991,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -3132,22 +3132,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -3453,7 +3453,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -3594,22 +3594,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -3915,7 +3915,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -4056,22 +4056,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -4377,7 +4377,7 @@
 .IF "$(GUI)" == "WNT"
 .IF "$(UPDATER)"=="YES"
 .IF "$(COM)"=="GCC"
-			gcc -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+			$(CC) -c -o$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE
 			$(CC) -c -Fo$(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.obj -DWNT $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF			# "$(COM)"=="GCC"
@@ -4518,22 +4518,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ELSE		
-		$(cc) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(cc) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(cc) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(cc) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
+		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.c
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
