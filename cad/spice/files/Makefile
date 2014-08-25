#
# $FreeBSD$
#
all:
	${SH} util/build FreeBSD default

CONFIGFILE?=	conf/FreeBSD

# Configuration parameters
VARLIST=	SYS_CFLAGS LDFLAGS INTERFACE_OPTS X_DIR
SYS_CFLAGS=	-Dbsd
LDFLAGS=	-lm -ltermcap
INTERFACE_OPTS=	-DWANT_MFB
.if defined(WITH_X11) && !empty(WITH_X11)
INTERFACE_OPTS+=-DWANT_X11
.else
VARLIST+=	INCX LIBX
.endif
X_DIR=		${LOCALBASE}

configure: ${CONFIGFILE}

${CONFIGFILE}::
.for V in ${VARLIST}
	echo "$V=${${V}}" >> ${CONFIGFILE}
.endfor

PREFIX?=	/usr/local

BINDIR=		${PREFIX}/bin
SHAREFILESDIR=	${PREFIX}/share/spice
HELPFILESDIR=	${SHAREFILESDIR}/helpdir
SCRIPTFILESDIR=	${SHAREFILESDIR}/scripts

PROGRAMS=	spice3 nutmeg sconvert help proc2mod multidec
HELPFILES=	spice.txt
SCRIPTFILES=	setplot spinit
SHAREFILES=	mfbcap news

MAN=	spice.1 nutmeg.1 sconvert.1 mfb.3 mfbcap.5
MANDIR=	${PREFIX}/man/man

.for P in ${PROGRAMS}
install:: ${DESTDIR}${BINDIR}/$P
${DESTDIR}${BINDIR}/$P: $P
	${BSD_INSTALL_PROGRAM} ${.ALLSRC} ${.TARGET}
.endfor
.for n in 1 3 5
. for M in ${MAN:M*.$n}
install:: ${DESTDIR}${MANDIR}${n}/$M
${DESTDIR}${MANDIR}${n}/$M: $M
	${BSD_INSTALL_MAN} ${.ALLSRC} ${.TARGET}
. endfor
.endfor
	ln -s -f spice.1 ${DESTDIR}${MANDIR}1/spice3.1

.for D in HELPFILES SCRIPTFILES SHAREFILES
. for F in ${${D}}
install:: ${DESTDIR}${${D}DIR}/$F
${DESTDIR}${${D}DIR}/$F: $F
	mkdir -p ${DESTDIR}${${D}DIR}
	${BSD_INSTALL_DATA} ${.ALLSRC} ${.TARGET}
. endfor
.endfor

.PATH: FreeBSD/obj/bin lib/helpdir lib/scripts lib man/man1 man/man3 man/man5
