# New ports collection makefile for:    fMSX
# Date created:         15 Oct 1996
# Whom:                 dk
#
# $FreeBSD$
#

PORTNAME=	fmsx
PORTVERSION=	2.7
CATEGORIES=	emulators
MASTER_SITES=	http://www.mavetju.org/download/adopted/ \
		http://fms.komkon.org/fMSX/
DISTNAME=	fMSX27
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dk@farm.org
COMMENT=	The Portable MSX/MSX2/MSX2+ Emulator

USE_REINPLACE=	yes
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
	${INSTALL_DATA} ${WRKSRC}/*.ROM ${WRKSRC}/*.FNT ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
