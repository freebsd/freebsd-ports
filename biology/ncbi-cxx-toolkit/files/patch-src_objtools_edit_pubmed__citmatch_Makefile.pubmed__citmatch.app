--- src/objtools/edit/pubmed_citmatch/Makefile.pubmed_citmatch.app.orig	2023-06-26 23:22:57 UTC
+++ src/objtools/edit/pubmed_citmatch/Makefile.pubmed_citmatch.app
@@ -2,7 +2,7 @@
 
 APP = pubmed_citmatch
 SRC = pubmed_citmatch
-LIB = $(OBJEDIT_LIBS) mlacli mla eutils uilist efetch $(SEQ_LIBS) \
+LIB = $(OBJEDIT_LIBS) mlacli mla eutils uilist efetch seqset $(SEQ_LIBS) \
       pubmed medlars pub medline biblio general xser xconnect xutil xncbi
 
 LIBS = $(DL_LIBS) $(NETWORK_LIBS) $(ORIG_LIBS)
