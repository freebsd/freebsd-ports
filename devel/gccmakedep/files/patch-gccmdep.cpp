--- ./gccmdep.cpp.orig	2013-06-28 08:58:38.395121863 +0200
+++ ./gccmdep.cpp	2013-06-28 08:57:53.213147106 +0200
@@ -9,7 +9,7 @@
 XCOMM
 
 TMP=mdep$$.tmp
-CC=CCCMD
+CC=${CC:-CCCMD}
 RM=RMCMD
 LN=LNCMD
 MV=MVCMD
