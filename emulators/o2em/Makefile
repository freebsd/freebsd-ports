# New ports collection makefile for:	o2em
# Date created:				24 June 2005
# Whom:					Gunter Wambaugh <techgunter@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=		o2em
PORTVERSION=		1.17
CATEGORIES=		emulators games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/o2em/:S/$/:1/} \
			http://o2em.sourceforge.net/files/:2
DISTFILES=		o2em117src.zip:1 \
			o2mainsamp.zip:2

MAINTAINER=		techgunter@yahoo.com
COMMENT=		An Odyssey2 / Videopac console emulator

LIB_DEPENDS=		alleg.41:${PORTSDIR}/devel/allegro

WRKSRC=			${WRKDIR}/o2em117src
MAKEFILE=		Makefile.freebsd
USE_ZIP=		yes
USE_GMAKE=		yes
USE_REINPLACE=		yes
MAKE_ENV=		LDFLAGS="${PTHREAD_LIBS}"

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|h|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/o2em ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/dis48 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${MKDIR} ${PREFIX}/${PORTNAME}/bios
	${INSTALL_DATA} ${WRKSRC}/O2ROM.BIN ${PREFIX}/${PORTNAME}/bios/o2rom.bin
	@${MKDIR} ${PREFIX}/${PORTNAME}/voice
	${INSTALL_DATA} ${WRKDIR}/*.WAV ${PREFIX}/${PORTNAME}/voice/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/O2EM.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/changelog.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${DOCSDIR}
.endif

post-install:
	${MKDIR} ${PREFIX}/o2em/roms
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
