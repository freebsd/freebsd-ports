--- Makefile.inc.orig	2015-12-09 12:02:38 UTC
+++ Makefile.inc
@@ -18,7 +18,7 @@ HEADERS   = $(MISCHDRS) $(OSFILESHDR) pa
 LIBCFLAGS += -I. $(CFLAGS) -DOSLOCK=\"$(OSLOCK)\" -DOSCONTEXT=\"$(OSCONTEXT)\"
 FHEADERS = fpapi.h f77papi.h f90papi.h
 # pkgconfig directory
-LIBPC = $(LIBDIR)/pkgconfig
+LIBPC = $(prefix)/libdata/pkgconfig
 
 all: $(SHOW_CONF) $(LIBS) utils tests cuda_sampling 
 .PHONY : all test fulltest tests testlib utils ctests ftests comp_tests null
