--- src/makjunix.mak.orig	2014-03-14 23:13:33.000000000 +0900
+++ src/makjunix.mak	2014-03-14 23:20:30.000000000 +0900
@@ -72,19 +72,20 @@
 
 
 ### Prefix for location of files
-PREFIX = /usr/local
+PREFIX?= /usr/local
 
 ### Location of binary
-BINLOC = $(PREFIX)/bin
+BINLOC = $(DESTDIR)$(PREFIX)/bin
 
 ### Name of target
-TARGET = vim
+PROG = jvim3
 
 ### Location of man page
-MANLOC = $(PREFIX)/man/man1
+MAN1PREFIX?=	${PREFIX}
+MANLOC = $(DESTDIR)$(MAN1PREFIX)/man/man1
 
 ### Location of help file
-HELPLOC = $(PREFIX)/lib
+HELPLOC = $(DESTDIR)$(PREFIX)/lib
 
 ### Program to run on installed binary
 STRIP = strip
@@ -100,7 +101,7 @@
 
 MANFILE = ../doc/vim.1
 
-HELPFILE = ../doc/vim.hlp
+HELPFILE = ../doc.j/vim.hlp
 
 #
 # PART 2: various choices
@@ -168,7 +169,8 @@
 
 DEFS = -DDIGRAPHS -DTERMCAP -DSOME_BUILTIN_TCAPS -DNO_FREE_NULL -DVIM_ISSPACE \
 		-DWEBB_COMPLETE -DWEBB_KEYWORD_COMPL \
-		-DVIM_HLP=\"$(HELPLOC)/vim.hlp\" \
+		-DVIM_HLP=\"$(HELPLOC)/jvim3.hlp\" \
+		-DDEFVIMRC_FILE=\"$(PREFIX)/etc/jvim3rc\" \
 		-DKANJI -DUCODE -DTRACK -DCRMARK -DFEXRC -DUSE_GREP -DUSE_TAGEX -DUSE_OPT $(FEPOPT)
 
 #
@@ -424,7 +426,7 @@
 ##   no changes required below this line      ##
 ################################################
 
-CFLAGS = -c $(MACHINE) $(DEFS)
+CFLAGS+=	$(CPPFLAGS) $(DEFS)
 
 INCL = vim.h globals.h param.h keymap.h macros.h ascii.h term.h unix.h structs.h proto.h
 
@@ -438,36 +440,32 @@
 
 GOBJ = grep.o alloc.o charset.o kanji.o regexp.o regsub.o u2s.o s2u.o
 
-all: $(TARGET) grep
+all: $(PROG) grep
 
-$(TARGET): $(OBJ) version.c
-	$(CC) $(CFLAGS) version.c
-	$(CC) -o $(TARGET) $(OBJ) version.o $(LIBS) $(FEPLIBS)
+$(PROG): $(OBJ) version.c
+	$(CC) -c $(CFLAGS) version.c
+	$(CC) -o $(PROG) $(OBJ) version.o $(LIBS) $(FEPLIBS)
 
 grep: $(GOBJ)
 	$(CC) -o grep/grep $(GOBJ) $(LIBS) $(FEPLIBS)
 
 debug: $(OBJ) version.c
-	$(CC) $(CFLAGS) version.c
-	$(CC) -o $(TARGET) -g $(OBJ) version.o $(LIBS)
+	$(CC) -c $(CFLAGS) version.c
+	$(CC) -o $(PROG) -g $(OBJ) version.o $(LIBS)
 
 ctags:
 	ctags *.c *.h
 
-install: $(TARGET)
-	-mkdir $(BINLOC)
-	cp $(TARGET) $(BINLOC)
-	chmod $(BINMOD) $(BINLOC)/$(TARGET)
-	$(STRIP) $(BINLOC)/$(TARGET)
-	-mkdir $(MANLOC)
-	cp $(MANFILE) $(MANLOC)
-	chmod $(MANMOD) $(MANLOC)/vim.1
-	-mkdir $(HELPLOC)
-	cp $(HELPFILE) $(HELPLOC)
-	chmod $(HELPMOD) $(HELPLOC)/vim.hlp
+install: $(PROG)
+	mkdir -p $(BINLOC)
+	${BSD_INSTALL_PROGRAM} ${PROG} ${BINLOC}
+	mkdir -p $(MANLOC)
+	${BSD_INSTALL_MAN} $(MANFILE) $(MANLOC)/jvim3.1
+	mkdir -p $(HELPLOC)
+	${BSD_INSTALL_DATA} $(HELPFILE) $(HELPLOC)/jvim3.hlp
 
 clean:
-	-rm -f $(OBJ) mkcmdtab.o version.o core $(TARGET) mkcmdtab cmdtab.h
+	-rm -f $(OBJ) mkcmdtab.o version.o core $(PROG) mkcmdtab cmdtab.h
 	-rm -f *.bak
 	-rm -f $(GOBJ)
 #	-rm -f jptab.h jptab
@@ -490,97 +488,97 @@
 ###########################################################################
 
 alloc.o:	alloc.c  $(INCL)
-	$(CC) $(CFLAGS) alloc.c
+	$(CC) -c $(CFLAGS) alloc.c
 
 unix.o:	unix.c  $(INCL)
-	$(CC) $(CFLAGS) unix.c
+	$(CC) -c $(CFLAGS) unix.c
 
 buffer.o:	buffer.c  $(INCL)
-	$(CC) $(CFLAGS) buffer.c
+	$(CC) -c $(CFLAGS) buffer.c
 
 charset.o:	charset.c  $(INCL)
-	$(CC) $(CFLAGS) charset.c
+	$(CC) -c $(CFLAGS) charset.c
 
 cmdcmds.o:	cmdcmds.c  $(INCL)
-	$(CC) $(CFLAGS) cmdcmds.c
+	$(CC) -c $(CFLAGS) cmdcmds.c
 
 cmdline.o:	cmdline.c  $(INCL) cmdtab.h ops.h
-	$(CC) $(CFLAGS) cmdline.c
+	$(CC) -c $(CFLAGS) cmdline.c
 
 csearch.o:	csearch.c  $(INCL)
-	$(CC) $(CFLAGS) csearch.c
+	$(CC) -c $(CFLAGS) csearch.c
 
 digraph.o:	digraph.c  $(INCL)
-	$(CC) $(CFLAGS) digraph.c
+	$(CC) -c $(CFLAGS) digraph.c
 
 edit.o:	edit.c  $(INCL) ops.h
-	$(CC) $(CFLAGS) edit.c
+	$(CC) -c $(CFLAGS) edit.c
 
 fileio.o:	fileio.c  $(INCL)
-	$(CC) $(CFLAGS) fileio.c
+	$(CC) -c $(CFLAGS) fileio.c
 
 getchar.o:	getchar.c  $(INCL)
-	$(CC) $(CFLAGS) getchar.c
+	$(CC) -c $(CFLAGS) getchar.c
 
 help.o:	help.c  $(INCL)
-	$(CC) $(CFLAGS) help.c
+	$(CC) -c $(CFLAGS) help.c
 
 linefunc.o:	linefunc.c  $(INCL)
-	$(CC) $(CFLAGS) linefunc.c
+	$(CC) -c $(CFLAGS) linefunc.c
 
 main.o:	main.c  $(INCL)
-	$(CC) $(CFLAGS) main.c
+	$(CC) -c $(CFLAGS) main.c
 
 mark.o:	mark.c  $(INCL)
-	$(CC) $(CFLAGS) mark.c
+	$(CC) -c $(CFLAGS) mark.c
 
 memfile.o:	memfile.c  $(INCL)
-	$(CC) $(CFLAGS) memfile.c
+	$(CC) -c $(CFLAGS) memfile.c
 
 memline.o:	memline.c  $(INCL)
-	$(CC) $(CFLAGS) memline.c
+	$(CC) -c $(CFLAGS) memline.c
 
 message.o:	message.c  $(INCL)
-	$(CC) $(CFLAGS) message.c
+	$(CC) -c $(CFLAGS) message.c
 
 misccmds.o:	misccmds.c  $(INCL)
-	$(CC) $(CFLAGS) misccmds.c
+	$(CC) -c $(CFLAGS) misccmds.c
 
 normal.o:	normal.c  $(INCL) ops.h
-	$(CC) $(CFLAGS) normal.c
+	$(CC) -c $(CFLAGS) normal.c
 
 ops.o:	ops.c  $(INCL) ops.h
-	$(CC) $(CFLAGS) ops.c
+	$(CC) -c $(CFLAGS) ops.c
 
 param.o:	param.c  $(INCL)
-	$(CC) $(CFLAGS) param.c
+	$(CC) -c $(CFLAGS) param.c
 
 quickfix.o:	quickfix.c  $(INCL)
-	$(CC) $(CFLAGS) quickfix.c
+	$(CC) -c $(CFLAGS) quickfix.c
 
 regexp.o:	regexp.c  $(INCL)
-	$(CC) $(CFLAGS) regexp.c
+	$(CC) -c $(CFLAGS) regexp.c
 
 regsub.o:	regsub.c  $(INCL)
-	$(CC) $(CFLAGS) regsub.c
+	$(CC) -c $(CFLAGS) regsub.c
 
 screen.o:	screen.c  $(INCL)
-	$(CC) $(CFLAGS) screen.c
+	$(CC) -c $(CFLAGS) screen.c
 
 search.o:	search.c  $(INCL) ops.h
-	$(CC) $(CFLAGS) search.c
+	$(CC) -c $(CFLAGS) search.c
 
 tag.o:	tag.c  $(INCL)
-	$(CC) $(CFLAGS) tag.c
+	$(CC) -c $(CFLAGS) tag.c
 
 term.o:	term.c  $(INCL)
-	$(CC) $(CFLAGS) term.c
+	$(CC) -c $(CFLAGS) term.c
 
 undo.o:	undo.c  $(INCL)
-	$(CC) $(CFLAGS) undo.c
+	$(CC) -c $(CFLAGS) undo.c
 
 window.o:	window.c  $(INCL)
-	$(CC) $(CFLAGS) window.c
+	$(CC) -c $(CFLAGS) window.c
 
 cmdtab.h: cmdtab.tab mkcmdtab
 	./mkcmdtab cmdtab.tab cmdtab.h
@@ -589,19 +587,19 @@
 	$(CC) -o mkcmdtab mkcmdtab.o
 
 mkcmdtab.o: mkcmdtab.c
-	$(CC) $(CFLAGS) mkcmdtab.c
+	$(CC) -c $(CFLAGS) mkcmdtab.c
 
 kanji.o: kanji.c $(INCL) jptab.h
-	$(CC) $(CFLAGS) kanji.c
+	$(CC) -c $(CFLAGS) kanji.c
 
 s2u.o: s2u.c
-	$(CC) $(CFLAGS) s2u.c
+	$(CC) -c $(CFLAGS) s2u.c
 
 u2s.o: u2s.c
-	$(CC) $(CFLAGS) u2s.c
+	$(CC) -c $(CFLAGS) u2s.c
 
 track.o: track.c $(INCL) jptab.h
-	$(CC) $(CFLAGS) track.c
+	$(CC) -c $(CFLAGS) track.c
 
 #jptab.h: jptab
 #	./jptab > jptab.h
@@ -610,19 +608,19 @@
 	$(CC) -o jptab jptab.o
 
 jptab.o: jptab.c
-	$(CC) $(CFLAGS) jptab.c
+	$(CC) -c $(CFLAGS) jptab.c
 
 fepseq.o: fepseq.c
-	$(CC) $(CFLAGS) fepseq.c
+	$(CC) -c $(CFLAGS) fepseq.c
 
 fepbow.o: fepbow.c
-	$(CC) $(CFLAGS) fepbow.c
+	$(CC) -c $(CFLAGS) fepbow.c
 
 fepcanna.o: fepcanna.c
-	$(CC) $(CFLAGS) -I/usr/local/canna/include fepcanna.c
+	$(CC) -c $(CFLAGS) -I${PREFIX}/include fepcanna.c
 
 feponew.o: feponew.c
-	$(CC) $(CFLAGS) feponew.c
+	$(CC) -c $(CFLAGS) feponew.c
 
 grep.o: grep/grep.c
-	$(CC) $(CFLAGS) -I. grep/grep.c
+	$(CC) -c $(CFLAGS) -I. grep/grep.c
