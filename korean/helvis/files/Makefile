# combined Makefile for ELVIS - a clone of `vi`
#
# After editing this Makefile as described below, you should...
#
# Use `make` to compile all programs
# Use `make install` to copy the programs to the BIN directory
# Use `make clean` to remove all object files
# Use `make clobber` to remove everything except source & documentation
# Use `make uue` to produce uuencoded compressed tar archives of the source
# Use `make sh` to produce shar archives of the source
#
# Several groups of Makefile settings are included below.  Choose *ONE* group
# of settings for your particular system, and leave the others commented out.
# The meanings of these settings are:
#	OBJ	filename extension for unlinked object files -- usually .o
#	EXE	filename extension for helvis executable file -- .exe, .tpp or null
#	COM	filename extension for executable support files -- .com, .tpp or null
#	EXTRA	version-specific object files used in helvis
#	EXTRA2	version-specific object files used in helvis & elvrec
#	LIBS	any special libraries, such as "-ltermcap"
#	BIN	directory where executables should be installed
#	CC	the C compiler command, possibly with "memory model" flags
#	CFLAGS	compiler flags used to select compile-time options
#	LNK	the linker command needed to link OBJ files (if not cc)
#	LFLAGS	linker flags used to select link-time options
#	SMALL	flag for special small memory model compilation -- usually null
#	LARGE	flag for special large memory model compilation -- usually null
#	OF	link flag to control the output file's name -- usually -o<space>
#	RF	flag used to denote "compile but don't link" -- usually -c
#	PROGS	the list of all programs
#	CHMEM	any extra commands to be run after ELVIS is linked
#	SORT	if the "tags" file must be sorted, then SORT=-DSORT
#	RM	the name of a program that deletes files
#	CP	name of a program that copies files -- copy or cp, usually
#	LN	name of a program that "links" files -- copy or ln, usually
#	SYS	type of system & compiler: unx/tos/os9/dos (maybe vms?)
#	DUMMY	usually nothing, but OS9 needs "dummy"
#	CFG	name of compiler configuration file -- usually null

#---- These settings are recommended for BSD 4.3 UNIX and SunOS 4.X ----
#---- For BSD386, add "-DTERMIOS" to CFLAGS
OBJ=	.o
EXE=	
COM=	
EXTRA=	unix$(OBJ)
EXTRA2=
LIBS=	-ltermcap
PREFIX?=/usr/local
BIN=	${PREFIX}/bin
CC=	cc
CFLAGS=	-Dbsd -O
SMALL=
LARGE=
OF=	-o ""
RF=	-c
PROGS=	helvis$(EXE) ctags$(COM) ref$(COM) elvrec$(COM) elvprsv$(COM)
CHMEM=
SORT=	-DSORT
RM=	rm -f
CP=	cp
LN=	ln -s
SYS=	unx
DUMMY=
CFG=

###########################################################################
###########################################################################
###                                                                     ###
###     The rest of this Makefile contains no user-serviceable parts    ###
###                                                                     ###
###########################################################################
###########################################################################

OBJS1=	blk$(OBJ) cmd1$(OBJ) cmd2$(OBJ) ctype$(OBJ) curses$(OBJ) cut$(OBJ)
OBJS2=	ex$(OBJ) input$(OBJ) main$(OBJ) misc$(OBJ) modify$(OBJ) move1$(OBJ)
OBJS3=	move2$(OBJ) move3$(OBJ) move4$(OBJ) move5$(OBJ) opts$(OBJ) recycle$(OBJ)
OBJS4=	redraw$(OBJ) regexp$(OBJ) regsub$(OBJ) system$(OBJ) tio$(OBJ) tmp$(OBJ)
OBJS5=	vars$(OBJ) vcmd$(OBJ) vi$(OBJ) hangul$(OBJ)
OBJS=	$(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5)

ALIAS=	alias$(OBJ)

###########################################################################

all: $(PROGS)
	@echo done.

helvis$(EXE): linkelv.$(SYS)
	@echo "helvis linked."

ctags$(COM): $(CFG) ctags.c wildcard.c
	$(CC) $(CFLAGS) $(SMALL) $(SORT) $(OF)ctags$(COM) ctags.c $(EXTRA2)

ref$(COM): $(CFG) ref.c
	$(CC) $(CFLAGS) $(SMALL) $(OF)ref$(COM) ref.c

elvrec$(COM): $(CFG) elvrec.c
	$(CC) $(CFLAGS) $(SMALL) $(OF)elvrec$(COM) elvrec.c $(EXTRA2)

ex$(COM): linkex.$(SYS)
	@echo "ex done."

vi$(COM): linkvi.$(SYS)
	@echo "vi done."

view$(COM): linkview.$(SYS)
	@echo "view done."

input$(COM): linkinput.$(SYS)
	@echo "input done."

shell$(COM): $(CFG) shell.c
	$(CC) $(CFLAGS) $(SMALL) $(OF)shell$(COM) shell.c

wildcard$(COM): $(CFG) wildcard.c ctype.c
	$(CC) $(CFLAGS) $(SMALL) $(OF)wildcard$(COM) wildcard.c

fmt$(COM): $(CFG) fmt.c
	$(CC) $(CFLAGS) $(SMALL) $(OF)fmt$(COM) fmt.c $(EXTRA2)

elvprsv$(COM): $(CFG) elvprsv.c amiprsv.c prsvunix.c prsvdos.c wildcard.c ctype.c
	$(CC) $(CFLAGS) $(SMALL) $(OF)elvprsv$(COM) elvprsv.c

##############################################################################
# "It all depends..."

$(OBJS): vi.h curses.h config.h regexp.h ctype.h

##############################################################################
# The way to link helvis is system dependent, and maybe compiler dependent too.

# helvis executable compilation rule for: AmigaDOS
linkelv.ami: $(OBJS) $(EXTRA) $(EXTRA2)
	$(LNK) $(LFLAGS) $(OF)helvis$(EXE) $(OBJS) $(EXTRA) $(EXTRA2) $(LIBS)
	$(CHMEM)
	@touch $@

# helvis executable compilation rule for: all unix, os9, tos, msc dos
linkelv.unx linkelv.tos linkelv.os9 linkelv.cl linkelv.xdos: \
		$(OBJS) $(EXTRA) $(EXTRA2)
	$(CC) $(LARGE) $(CFLAGS) $(OF)helvis$(EXE) $(OBJS) $(EXTRA) $(EXTRA2) $(LIBS)
	$(CHMEM)
	@touch $@

linkelv.dos: linkelv.$(CC)

# helvis executable compilation rule for: borland tcc, bcc
linkelv.bcc linkelv.tcc: $(CFG) $(OBJS) $(EXTRA) $(EXTRA2)
	$(CC) $(CFLAGS) $(LIBS)
	@echo done > linkelv.$(CC)

linkelv.vms: $(OBJS) $(EXTRA) $(EXTRA2)
	link$(OF)helvis.exe main,$(CFG)/opt

##############################################################################

# borland/turbo c config files
borland.cfg: $(DUMMY)
	echo $(TC_CFLAGS1)> borland.cfg
	echo $(TC_CFLAGS2)>> borland.cfg

borland.rsp: $(DUMMY)
	echo $(EFLAGS) $(OF)helvis$(EXE) > borland.rsp
	echo $(OBJS1)>> borland.rsp
	echo $(OBJS2)>> borland.rsp
	echo $(OBJS3)>> borland.rsp
	echo $(OBJS4)>> borland.rsp
	echo $(OBJS5)>> borland.rsp
	echo $(EXTRA)>> borland.rsp

##############################################################################
# helvis executable compilation rule for: AmigaDOS
linkex.ami: alias.o
	$(LNK) $(LFLAGS) $(OF)ex$(EXE) alias.o $(LIBS)

linkex.unx linkex.tos linkex.xdos linkex.dos linkex.vms: $(CFG) alias.c
	$(CC) $(CFLAGS) $(SMALL) $(OF)ex$(COM) alias.c

linkex.os9: $(DUMMY)
	@echo done >/nil

linkvi.ami linkvi.unx linkvi.tos linkvi.xdos linkvi.dos linkvi.vms: ex$(COM)
	$(CP) ex$(COM) vi$(COM)

linkvi.os9: alias.r
	$(CC) $(CFLAGS) $(OF)vi$(COM) alias.r
	@touch $@

linkview.ami linkview.unx linkview.tos linkview.xdos linkview.dos linkview.vms: ex$(COM)
	$(CP) ex$(COM) view$(COM)

linkview.os9: alias.r
	$(CC) $(CFLAGS) $(OF)view$(COM) alias.r
	@touch $@

linkinput.ami linkinput.unx linkinput.tos linkinput.xdos linkinput.dos linkinput.vms: ex$(COM)
	$(CP) ex$(COM) input$(COM)

linkinput.os9: alias.r
	$(CC) $(CFLAGS) $(OF)input$(COM) alias.r
	@touch $@

##############################################################################
# installation is system-dependent

install: $(PROGS) inst.$(SYS)
	@echo Installation complete.

inst.ami: $(DUMMY)
	MakeDir $(BIN)/Elvis
	Assign Elvis: $(BIN)/Elvis
	$(CP) $(PROGS) Elvis:
	@echo ::: YOU STILL NEED TO EDIT THE S:STARTUP-SEQUENCE FILE,
	@echo ::: TO HAVE TEMP FILES PRESERVED AFTER A SYSTEM CRASH.


inst.unx: $(DUMMY)
	$(CP) $(PROGS) $(BIN)
	(cd $(BIN); chmod 755 $(PROGS))
	(cd $(BIN); chown bin $(PROGS))
	(cd $(BIN); chown root elvprsv$(COM) elvrec$(COM))
	(cd $(BIN); chmod 4755 elvprsv$(COM) elvrec$(COM))
	-$(LN) $(BIN)/helvis $(BIN)/hvi
	-$(LN) $(BIN)/helvis $(BIN)/hex
	-$(LN) $(BIN)/helvis $(BIN)/hview
	-$(LN) $(BIN)/helvis $(BIN)/hinput
	test -d /var/preserve || (mkdir /var/preserve; chmod 755 /var/preserve)
	@if test -d /etc/rc2.d; then \
		echo $(BIN)/elvprsv /tmp/elv* >/etc/rc2.d/S03elvis; \
	else \
		echo "::: YOU STILL NEED TO EDIT THE /ETC/RC FILE, OR WHATEVER,"; \
		echo "::: TO HAVE TEMP FILES BE PRESERVED AFTER A SYSTEM CRASH."; \
	fi
#	sh instman.sh $(PROGS)

inst.dos: $(DUMMY)
	for %a in ($(PROGS1)) do copy %a $(BIN)
	for %a in ($(PROGS2)) do copy %a $(BIN)
	$(CP) $(BIN)\ex$(COM) $(BIN)\vi$(COM)
	$(CP) $(BIN)\ex$(COM) $(BIN)\view$(COM)
	$(CP) $(BIN)\ex$(COM) $(BIN)\input$(COM)
	-mkdir c:\preserve
	-mkdir c:\tmp
	@echo ::: YOU STILL NEED TO EDIT YOUR AUTOEXEC.BAT FILE TO
	@echo ::: HAVE TEMP FILES BE PRESERVED AFTER A SYSTEM CRASH.

inst.xdos: $(DUMMY)
	$(CP) $(PROGS) $(BIN)
	$(CP) ex$(COM) $(BIN)/vi$(COM)
	$(CP) ex$(COM) $(BIN)/view$(COM)
	$(CP) ex$(COM) $(BIN)/input$(COM)
	@echo ::: YOU WILL NEED TO EDIT THE AUTOEXEC.BAT FILE TO
	@echo ::: HAVE TEMP FILES BE PRESERVED AFTER A SYSTEM CRASH.

inst.tos: $(DUMMY)
	$(CP) $(PROGS) $(BIN)

inst.os9: $(DUMMY)
	$(CP) $(PROGS) -rw=$(BIN)
	chd $(BIN); attr -epenprnpw $(PROGS)
	@echo ::: YOU STILL NEED TO EDIT THE /DD/STARTUP FILE, OR WHATEVER,
	@echo ::: TO HAVE TEMP FILES BE PRESERVED AFTER A SYSTEM CRASH.

inst.vms: $(DUMMY)
	@echo how?

##############################################################################
# clobbering is system dependent, because DOS's "copy" can't handle multiple
# filenames

clobber: clean clob.$(SYS)
	@echo -n

clean: $(DUMMY)
	$(RM) *$(OBJ) 
	$(RM) elvis?.uue 
	$(RM) elvis?.sh 
	$(RM) core
	$(RM) linkelv.$(SYS)

clob.unx clob.tos clob.os9 clob.xdos clob.vms: $(DUMMY)
	$(RM) tags refs $(PROGS)

clob.dos : $(DUMMY)
	for %a in ($(PROGS1)) do $(RM) %a
	for %a in ($(PROGS2)) do $(RM) %a
	for %a in (tags refs) do $(RM) %a
