#
# $FreeBSD$
#
# QuakeWorld/MVDSV Makefile for FreeBSD
#
#	- now should build on non-x86
#	- no longer requires gmake(1)
#	- debug targets support axed out
#	- couple of useful knobs added
#
# Created on Wednesday, May 21 2003 by Alexey Dokuchaev <danfe@regency.nsu.ru>
#

DO_CFLAGS =	${CFLAGS} -funsigned-char -I${LOCALBASE}/include -Dstricmp=strcasecmp \
		-DSERVERONLY -DUSE_PR2

.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
DO_CFLAGS +=	-Did386
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
DO_CFLAGS +=	-O9 -pipe -s -ffast-math -funroll-loops -fomit-frame-pointer -fexpensive-optimizations
.endif

########################################################################
## MVDSV
########################################################################

SV_OBJS = \
		pr_cmds.o \
		pr_edict.o \
		pr_exec.o \
\
		pr2_cmds.o \
		pr2_edict.o \
		pr2_exec.o \
		pr2_vm.o \
\
		sv_ccmds.o \
		sv_demo.o \
		sv_ents.o \
		sv_init.o \
		sv_login.o \
		sv_main.o \
		sv_mod_frags.o \
		sv_model.o \
		sv_move.o \
		sv_nchan.o \
		sv_phys.o \
		sv_send.o \
		sv_sys_unix.o \
		sv_user.o \
\
		cmd.o \
		common.o \
		crc.o \
		cvar.o \
		mathlib.o \
		mdfour.o \
		net_chan.o \
		net_udp.o \
		pmove.o \
		pmovetst.o \
		sha1.o \
		version.o \
		world.o \
		zone.o \
\
		pcre/chartables.o \
		pcre/get.o \
		pcre/pcre.o

.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
SV_AS_OBJS = \
		math.o \
		worlda.o
.endif

SV_LIBS = -lm

########################################################################
## QWDTOOLS
########################################################################

QWDTOOLS_OBJS = \
		qwdtools/dem_parse.o \
		qwdtools/dem_send.o \
		qwdtools/ini.o \
		qwdtools/init.o \
		qwdtools/main.o \
		qwdtools/marge.o \
		qwdtools/qwz.o \
		qwdtools/sync.o \
		qwdtools/tools.o

########################################################################

.c.o:
		${CC} ${DO_CFLAGS} -I. -c $< -o $*.o

.s.o:
		${CC} ${DO_CFLAGS} -DELF -x assembler-with-cpp -c $< -o $*.o

all:	mvdsv qwdtools

mvdsv:	${SV_OBJS} ${SV_AS_OBJS} .PHONY
		${CC} ${CFLAGS} -o ../mvdsv ${SV_OBJS} ${SV_AS_OBJS} ${SV_LIBS}

qwdtools:	${QWDTOOLS_OBJS} .PHONY
		${CC} ${CFLAGS} -o ../qwdtools ${QWDTOOLS_OBJS} ${SV_LIBS}

clean:
		-rm -f *.o *.core
