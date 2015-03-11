--- modules/modperl/Makefile.inc.orig	2015-02-12 20:51:46.000000000 +0000
+++ modules/modperl/Makefile.inc	2015-02-26 02:56:35.000000000 +0000
 PERL_LD    := $(shell $(PERL) -MExtUtils::Embed -e ldopts)
 # Perl API is ugly, casting string literals to char* and redeclaring functions :(
 PERL_CXX   += -Wno-write-strings -Wno-redundant-decls -Wno-missing-declarations
-PERL_CXX   += -Wno-type-limits -Wno-sign-compare -Wno-strict-overflow -Wno-unused-value
+PERL_CXX   += -Wno-sign-compare -Wno-strict-overflow -Wno-unused-value
 # perl 5.20 will fix this warning: https://rt.perl.org/Public/Bug/Display.html?id=120670
 PERL_CXX   += -Wno-reserved-user-defined-literal -Wno-literal-suffix
 # This is for SWIG
