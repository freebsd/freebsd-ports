--- ../solenv/inc/_tg_shl.mk.orig	Wed Jan  2 12:23:22 2002
+++ ../solenv/inc/_tg_shl.mk	Tue May 28 12:02:12 2002
@@ -345,22 +345,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL1TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -770,22 +770,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL2TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -1195,22 +1195,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL3TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -1620,22 +1620,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL4TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -2045,22 +2045,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL5TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -2470,22 +2470,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL6TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -2895,22 +2895,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL7TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -3320,22 +3320,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL8TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -3745,22 +3745,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL9TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
@@ -4170,22 +4170,22 @@
 .IF "$(UPDATER)"=="YES"
 .IF "$(OS)"=="SOLARIS"
 .IF "$(COM)"=="GCC"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ELSE		
-		$(CC) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -KPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF		
 .ENDIF
 .IF "$(OS)"=="MACOSX"
-		$(CC) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -dynamic -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@echo "------------------------------"
 		@echo "Updating static data member initializations"
 		@+dmake -f $(SOLARENV)$/$(OUTPATH)$/inc/makefile.mk $(MFLAGS) $(CALLMACROS) "PRJ=$(PRJ)" "PRJNAME=$(PRJNAME)" "TARGET=$(TARGET)"
 .ENDIF
 .IF "$(OS)"=="LINUX" || "$(OS)"=="NETBSD" || "$(OS)"=="FREEBSD"
-		$(CC) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -c -fPIC -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 .ENDIF
 .IF "$(OS)"=="IRIX"
-		$(CC) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
+		$(CXX) -o $(SLO)$/{$(subst,$(UPD)$(DLLPOSTFIX),_dflt $(SHL10TARGET))}_version.o -DUNX $(ENVCDEFS) -I$(INCCOM) $(SOLARENV)$/src$/version.cxx
 		@+if ( ! -e $(SOLARLIBDIR) ) mkdir $(SOLARLIBDIR)
 		@+if ( ! -e $(SOLARLIBDIR)/so_locations ) touch $(SOLARLIBDIR)/so_locations
 .ENDIF			# "$(OS)"=="IRIX"
