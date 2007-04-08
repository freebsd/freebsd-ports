--- texk/make/paths.mk.orig	Sat May  8 19:05:24 2004
+++ texk/make/paths.mk	Tue Jan 11 01:15:49 2005
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
