# New ports collection makefile for:    fMSX
# Date created:         15 Oct 1996
# Whom:                 dk
#
# $FreeBSD$
#

PORTNAME=	fmsx
PORTVERSION=	3.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.mavetju.org/download/adopted/:code \
		http://fms.komkon.org/fMSX/:code \
		http://fms.komkon.org/fMSX/src/:rom
DISTFILES=	fMSX30.tar.Z:code \
		MSX.ROM:rom MSX2.ROM:rom MSX2EXT.ROM:rom MSX2P.ROM:rom \
		MSX2PEXT.ROM:rom FMPAC.ROM:rom DISK.ROM:rom MSXDOS2.ROM:rom \
		PAINTER.ROM:rom KANJI.ROM:rom
DIST_SUBDIR=	fmsx30
EXTRACT_ONLY=	fMSX30.tar.Z

MAINTAINER=	dk@farm.org
COMMENT=	The Portable MSX/MSX2/MSX2+ Emulator

REINPLACE_ARGS=	-i ""

USE_XLIB=	yes
RESTRICTED=	Legal status of distributed ROM images unclear
WRKSRC=		${WRKDIR}/MSX

OPTIONS=	BPP8 "With BPP8" Off \
		BPP16 "With BPP16" Off \
		BPP24 "With BPP24" Off \
		BPP32 "With BPP32 (see pkg-message)" On

.include <bsd.port.pre.mk>

post-patch:
.ifdef(WITH_BPP32) || defined(PACKAGE_BUILDING) || defined(BATCH)
	${REINPLACE_CMD} -e 's/%%BPP%%/BPP32/' ${WRKSRC}/Makefile
.endif
.ifdef(WITH_BPP24)
	${REINPLACE_CMD} -e 's/%%BPP%%/BPP24/' ${WRKSRC}/Makefile
.endif
.ifdef(WITH_BPP16)
	${REINPLACE_CMD} -e 's/%%BPP%%/BPP16/' ${WRKSRC}/Makefile
.endif
.ifdef(WITH_BPP8)
	${REINPLACE_CMD} -e 's/%%BPP%%/BPP8/' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fmsx ${PREFIX}/bin
	${REINPLACE_CMD} "s,PREFIX,${PREFIX},g" ${PREFIX}/bin/fmsx
	${INSTALL_PROGRAM} ${WRKSRC}/fmsx ${PREFIX}/bin/fmsx.bin
	${INSTALL_PROGRAM} ${WRKSRC}/rddsk ${PREFIX}/bin/fmsx-rddsk
	${INSTALL_PROGRAM} ${WRKSRC}/wrdsk ${PREFIX}/bin/fmsx-wrdsk
	${MKDIR} ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/*.FNT ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.ROM ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
