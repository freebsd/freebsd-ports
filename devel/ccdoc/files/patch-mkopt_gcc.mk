--- mkopt_gcc.mk.orig	2004-10-06 16:35:47 UTC
+++ mkopt_gcc.mk
@@ -1,17 +1,17 @@
 # ================================================
 # GCC compiler, optimized mode, any platform.
 # ================================================
-PERL = perl
+PERL = %%PERL%%
 PLATFORM = $(shell $(PERL) ../utils/platform.pl)
 CCDOC_CID = bin_opt_gcc_${PLATFORM}
 BIN_DIR = ../${CCDOC_CID}
 OBJ_EXT = o
-CXX = g++
-CXX_FLAGS = -c -pedantic -Wall -O -DCCDOC_OPT -DCCDOC_CID=\"${CCDOC_CID}\"
-CXX_OUT = -o 
+CXX = %%CXX%%
+CXX_FLAGS = -c -pedantic -Wall %%CXXFLAGS%% -DCCDOC_OPT -DCCDOC_CID=\"${CCDOC_CID}\"
+CXX_OUT = -o
 LINK_TARG = ${BIN_DIR}/ccdoc.exe
-LINK = g++
-LINK_FLAGS = -g
-LINK_OUT = -o 
+LINK = %%CXX%%
+LINK_FLAGS = %%CXXFLAGS%%
+LINK_OUT = -o
 
 include mktargs.mk
