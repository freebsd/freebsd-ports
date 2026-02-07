--- taste/unix.mk.orig	1999-11-21 06:34:03 UTC
+++ taste/unix.mk
@@ -27,7 +27,7 @@ taste:          tastep.o taste.o tc.o tl
 		$(CC) $(CFLAGS) -otaste taste.o tl.o tc.o\
                                         tastes.o tastep.o
 
-tastep.o:       taste.atg
+tastep.o taste.o:       taste.atg
 		$(COCOR) taste.atg
 		$(CC) $(CFLAGS) -c taste.c tastep.c tastes.c
 
@@ -35,7 +35,7 @@ pretty:         prettyp.o pretty.o prett
 		$(CC) $(CFLAGS) -opretty pretty.o prettypr.o \
                                          prettys.o prettyp.o
 
-prettyp.o:      pretty.atg
+prettyp.o pretty.o:      pretty.atg
 		$(COCOR) pretty.atg
 		$(CC) $(CFLAGS) -c pretty.c prettyp.c prettys.c
 
@@ -43,7 +43,7 @@ xref:           xrefp.o xref.o crossref.
 		$(CC) $(CFLAGS) -oxref xref.o crossref.o \
                                        xrefs.o xrefp.o
 
-xrefp.o:        xref.atg
+xrefp.o xref.o:        xref.atg
 		$(COCOR) xref.atg
 		$(CC) $(CFLAGS) -c xref.c xrefp.c xrefs.c
 
