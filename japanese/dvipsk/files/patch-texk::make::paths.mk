--- make/paths.mk.orig	Wed Nov 13 05:54:37 2002
+++ make/paths.mk	Fri Sep 17 13:22:23 2004
@@ -61,7 +61,7 @@
 dvilj_latex2e_macrodir = $(texinputdir)/latex/dvilj
 
 # mktex.cnf, texmf.cnf, etc.
-web2cdir = $(texmf)/web2c
+web2cdir = $(texmf)/web2c/ptex
 
 # The top-level font directory.
 fontdir = $(texmf)/fonts
@@ -80,7 +80,7 @@
 fontnamedir = $(texmf)/fontname
 
 # For dvips configuration files, psfonts.map, etc.
-dvipsdir = $(texmf)/dvips
+dvipsdir = $(texmf)/dvips/ptex
 
 # For dvips .pro files, gsftopk's render.ps, etc.
 psheaderdir = $(dvipsdir)
