--- ../connectivity/source/parse/makefile.mk.orig	Sat Mar  2 21:01:23 2002
+++ ../connectivity/source/parse/makefile.mk	Sat Mar  2 21:03:09 2002
@@ -97,7 +97,11 @@
 $(MISC)$/sqlbison.cxx: sqlbison.y
 	+bison -v -d -pSQLyy -l -bsql -o$(MISC)$/sqlbison.cxx sqlbison.y
 	-$(MKDIR) $(OUT)$/inc$/connectivity
+.IF "$(OS)"=="FREEBSD" || "$(OS)"=="NETBSD"
+	+$(COPY) $(MISC)$/sqlbison.hxx $(OUT)$/inc$/connectivity$/sqlbison.hxx
+.ELSE
 	+$(COPY) $(MISC)$/sqlbison.cxx.h $(OUT)$/inc$/connectivity$/sqlbison.hxx
+.ENDIF
 
 $(SLO)$/sqlbison.obj : $(MISC)$/sqlbison.cxx
 
