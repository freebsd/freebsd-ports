# New ports collection makefile for:    fMSX
# Date created:         15 Oct 1996
# Whom:                 dk
#
# $FreeBSD$
#

PORTNAME=	fmsx
PORTVERSION=	3.5.1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.mavetju.org/download/adopted/:code \
		http://fms.komkon.org/fMSX/:code \
		http://fms.komkon.org/fMSX/src/:rom
DISTFILES=	fMSX351.zip:code \
		MSX.ROM:rom MSX2.ROM:rom MSX2EXT.ROM:rom MSX2P.ROM:rom \
		MSX2PEXT.ROM:rom FMPAC.ROM:rom DISK.ROM:rom MSXDOS2.ROM:rom \
		PAINTER.ROM:rom KANJI.ROM:rom
DIST_SUBDIR=	fmsx351
EXTRACT_ONLY=	fMSX351.zip

MAINTAINER=	dk@farm.org
COMMENT=	The Portable MSX/MSX2/MSX2+ Emulator

BROKEN=		does not fetch

USE_XORG=	xi x11
USE_ZIP=	yes
USE_GMAKE=	yes
USE_DOS2UNIX=	EMULib/NetUnix.c EMULib/Rules.Unix
RESTRICTED=	Legal status of distributed ROM images unclear
WRKSRC=		${WRKDIR}

OPTIONS=	BPP8 "With BPP8" Off \
		BPP16 "With BPP16" Off \
		BPP24 "With BPP24" Off \
		BPP32 "With BPP32 (see pkg-message)" On

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/fMSX/Unix/Makefile \
		${WRKSRC}/EMULib/Rules.Unix
.ifdef(WITH_BPP32) || defined(PACKAGE_BUILDING) || defined(BATCH)
	${REINPLACE_CMD} -e 's/BPP16/BPP32/' ${WRKSRC}/fMSX/Unix/Makefile
.endif
.ifdef(WITH_BPP24)
	${REINPLACE_CMD} -e 's/BPP16/BPP24/' ${WRKSRC}/fMSX/Unix/Makefile
.endif
.ifdef(WITH_BPP16)
	${REINPLACE_CMD} -e 's/BPP16/BPP16/' ${WRKSRC}/fMSX/Unix/Makefile
.endif
.ifdef(WITH_BPP8)
	${REINPLACE_CMD} -e 's/BPP16/BPP8/' ${WRKSRC}/fMSX/Unix/Makefile
.endif

do-build:
	cd ${WRKSRC}/fMSX/Unix && ${GMAKE}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fmsx ${PREFIX}/bin
	${REINPLACE_CMD} -i "" -e "s,PREFIX,${PREFIX},g" ${PREFIX}/bin/fmsx
	${INSTALL_PROGRAM} ${WRKSRC}/fMSX/Unix/fmsx ${PREFIX}/bin/fmsx.bin
	${MKDIR} ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/fMSX/ROMs/*.FNT ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.ROM ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fMSX/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
