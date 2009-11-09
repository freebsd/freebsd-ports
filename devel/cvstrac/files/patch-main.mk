--- ./main.mk.orig	2009-11-09 17:16:12.000000000 -0500
+++ ./main.mk	2009-11-09 17:16:19.000000000 -0500
@@ -115,7 +115,7 @@
 	$(BCC) -o maketestdb $(SRCDIR)/maketestdb.c $(LIBSQLITE)
 
 $(APPNAME):	headers $(OBJ)
-	$(TCC) -o $(APPNAME) $(OBJ) $(LIBSQLITE)
+	$(TCC) -o $(APPNAME) $(OBJ) $(LIBSQLITE) -lm
 
 index.html:	$(SRCDIR)/webpage.html $(SRCDIR)/VERSION
 	sed -f $(SRCDIR)/VERSION $(SRCDIR)/webpage.html >index.html
