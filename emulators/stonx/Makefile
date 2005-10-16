# New ports collection makefile for:    STonX
# Date created:         3rd August, 1997
# Whom:                 Tobias Reifenberger <tr@freebsd.mayn.de>
#
# $FreeBSD$
#

PORTNAME=	stonx
PORTVERSION=	0.6.7e
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.complang.tuwien.ac.at/pub/nino/stonx-current/
DISTNAME=	STonX-0.6.7-epsilon

MAINTAINER=	treif@mayn.de
COMMENT=	AtariST emulator

RESTRICTED=	"tos.img is copyrighted"

TOSIMG?=	tos.img
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes

pre-build:
	${CP} ${DISTDIR}/${TOSIMG} ${WRKSRC}/tos.img

post-build:
	(cd ${WRKSRC}; make fnttobdf fonts)

# Installing
#
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib/X11/STonX
FNTDIR=	${PREFIX}/lib/X11/fonts/misc

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
	${INSTALL_DATA} ${WRKSRC}/$f ${LIBDIR}
.endfor

	@${ECHO_MSG} "===> Installing fonts"
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/data/$f ${FNTDIR}
	@${GZIP_CMD} ${FNTDIR}/$f
.endfor
	@mkfontdir ${FNTDIR}

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Installing docs"
	@${MKDIR} ${LIBDIR}/docs
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/$f ${LIBDIR}/docs
.endfor
.endif

post-install:
	${X11BASE}/bin/mkfontdir ${FNTDIR}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${TOSIMG})
IGNORE="Please get a ROM dump from your AtariST and save it as"\
"\"${TOSIMG}\" in \"${DISTDIR}\" manually, and then make install again"
.endif

.include <bsd.port.post.mk>
