# New ports collection makefile for:    STonX
# Version required:     0.6.7
# Date created:         3rd August, 1997
# Whom:                 Tobias Reifenberger <tr@freebsd.mayn.de>
#
# $FreeBSD$
#

DISTNAME=       STonX-0.6.7-epsilon
PKGNAME=	stonx-0.6.7e
CATEGORIES=     emulators
MASTER_SITES=   ftp://ftp.complang.tuwien.ac.at/pub/nino/stonx-current/
DISTFILES=      ${DISTNAME}${EXTRACT_SUFX} tos.img

MAINTAINER=     tr@freebsd.mayn.de

BROKEN="fetch"

RESTRICTED=     "tos.img is Copyrighted"
NO_PACKAGE=	${RESTRICTED}

IGNOREFILES=	tos.img
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
HAS_CONFIGURE=	yes

# Source building
#
pre-build:
	${CP} ${DISTDIR}/tos.img ${WRKSRC}

post-build:
	(cd ${WRKSRC}; make fnttobdf fonts)

# Installing
#
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib/STonX
FNTDIR= ${X11BASE}/lib/X11/fonts/misc

DATA=	tos.img cartridge.img Keysyms Keysyms.G atari/FLOPPY-4MB \
	atari/bench1.pas atari/bench1.prg atari/final.tos
DOCS=	../COPYING DEBUGGING FONTS INSTALL PROGRAMS README RELEASE_NOTES \
	TOS-VERSIONS
FONTS=	System0-iso.pcf System0.pcf System1-iso.pcf System1.pcf \
	System2-iso.pcf System2.pcf

pre-install:
	@${ECHO_MSG} "#!/bin/sh" > ${WRKSRC}/stonx.script
	@${ECHO_MSG} "cd ${LIBDIR}" >> ${WRKSRC}/stonx.script
	@${ECHO_MSG} "${BINDIR}/stonx.bin -noaudio \
		-disk A:FLOPPY-4MB -fs C:." >> ${WRKSRC}/stonx.script

do-install:
	@${ECHO_MSG} "===> Installing programs"
	${INSTALL_SCRIPT} ${WRKSRC}/stonx.script ${BINDIR}/stonx
	${INSTALL_PROGRAM} ${WRKSRC}/stonx ${BINDIR}/stonx.bin

	@${ECHO_MSG} "===> Installing data"
	@${MKDIR} ${LIBDIR}
.for f in ${DATA}
	@${INSTALL_DATA} ${WRKSRC}/$f ${LIBDIR}
.endfor

	@${ECHO_MSG} "===> Installing fonts"
.for f in ${FONTS}
	@${INSTALL_DATA} ${WRKSRC}/data/$f ${FNTDIR}
	@gzip -f ${FNTDIR}/$f
.endfor
	@mkfontdir ${FNTDIR}

	@${ECHO_MSG} "===> Installing docs"
	@${MKDIR} ${LIBDIR}/docs
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/$f ${LIBDIR}/docs
.endfor

.include <bsd.port.mk>
