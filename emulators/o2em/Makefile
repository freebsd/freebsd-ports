# Created by: Gunter Wambaugh <techgunter@yahoo.com>
# $FreeBSD$

PORTNAME=	o2em
PORTVERSION=	1.17
PORTREVISION=	3
CATEGORIES=	emulators games
MASTER_SITES=	SF/${PORTNAME}/OldFiles:1 \
		http://o2em.sourceforge.net/files/:2
DISTFILES=	o2em117src.zip:1 \
		o2mainsamp.zip:2

MAINTAINER=	techgunter@yahoo.com
COMMENT=	Odyssey2 / Videopac console emulator

LIB_DEPENDS=	liballeg.so:devel/allegro

WRKSRC=		${WRKDIR}/o2em117src
MAKEFILE=	Makefile.freebsd
USES=		gmake zip
LDFLAGS+=	-lpthread

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|h|txt)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/o2em ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/dis48 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bios
	${INSTALL_DATA} ${WRKSRC}/O2ROM.BIN ${STAGEDIR}${PREFIX}/${PORTNAME}/bios/o2rom.bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/voice
	${INSTALL_DATA} ${WRKDIR}/*.WAV ${STAGEDIR}${PREFIX}/${PORTNAME}/voice/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/O2EM.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/changelog.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${STAGEDIR}${DOCSDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/o2em/roms

.include <bsd.port.mk>
