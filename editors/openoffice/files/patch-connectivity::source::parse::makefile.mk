--- ../connectivity/source/parse/makefile.mk.orig	Wed Mar  6 10:39:52 2002
+++ ../connectivity/source/parse/makefile.mk	Wed Mar  6 10:40:07 2002
@@ -95,6 +95,7 @@
 	+flex -i -8 -PSQLyy -L -o$(MISC)$/sqlflex.cxx sqlflex.l
 
 $(MISC)$/sqlbison.cxx: sqlbison.y
+	+bison -v -d -pSQLyy -l -bsql -o$(MISC)$/sqlbison.cxx.h sqlbison.y
 	+bison -v -d -pSQLyy -l -bsql -o$(MISC)$/sqlbison.cxx sqlbison.y
 	-$(MKDIR) $(OUT)$/inc$/connectivity
 	+$(COPY) $(MISC)$/sqlbison.cxx.h $(OUT)$/inc$/connectivity$/sqlbison.hxx
