--- xdvik-22.40w/texk/make/paths.mk.orig	Sat Jun 12 12:13:14 2004
+++ xdvik-22.40w/texk/make/paths.mk	Sat Jun 12 12:13:04 2004
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
