#
# $FreeBSD$
#
build:
	${SH} util/build FreeBSD default
	strip ${PROGRAMS:S,^,FreeBSD/obj/bin/,}

PREFIX?=	/usr/local

BINDIR=		${PREFIX}/bin
SHAREFILESDIR=	${PREFIX}/share/spice
HELPFILESDIR=	${SHAREFILESDIR}/helpdir
SCRIPTFILESDIR=	${SHAREFILESDIR}/scripts

FILESGROUPS=	PROGRAMS HELPFILES SCRIPTFILES SHAREFILES

PROGRAMSMODE=	${BINMODE}
PROGRAMSOWN=	${BINOWN}
PROGRAMSGRP=	${BINGRP}

PROGRAMS=	spice3 nutmeg sconvert help proc2mod multidec
HELPFILES=	spice.txt
SCRIPTFILES=	setplot spinit
SHAREFILES=	mfbcap news

MAN=	spice.1 nutmeg.1 sconvert.1 mfb.3 mfbcap.5
MLINKS=	spice.1 spice3.1
MANDIR=	${PREFIX}/man/man

beforeinstall:
	mkdir -p ${DESTDIR}${HELPFILESDIR} ${DESTDIR}${SCRIPTFILESDIR}

.PATH: FreeBSD/obj/bin lib/helpdir lib/scripts lib man/man1 man/man3 man/man5
.include <bsd.prog.mk>
