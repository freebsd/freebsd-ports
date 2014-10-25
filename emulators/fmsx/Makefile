# Created by: dk
# $FreeBSD$

PORTNAME=	fmsx
PORTVERSION=	3.7
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/fMSX/:code \
		http://fms.komkon.org/fMSX/src/:rom
DISTFILES=	fMSX37.zip:code \
		MSX.ROM:rom MSX2.ROM:rom MSX2EXT.ROM:rom MSX2P.ROM:rom \
		MSX2PEXT.ROM:rom FMPAC.ROM:rom DISK.ROM:rom MSXDOS2.ROM:rom \
		PAINTER.ROM:rom KANJI.ROM:rom
DIST_SUBDIR=	fmsx37
EXTRACT_ONLY=	fMSX37.zip

MAINTAINER=	dk@farm.org
COMMENT=	Portable MSX/MSX2/MSX2+ Emulator

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

USE_XORG=	xi x11
USES=		gmake dos2unix zip
DOS2UNIX_FILES=	EMULib/Unix/LibUnix.c EMULib/Unix/NetUnix.c EMULib/Rules.gcc \
		EMULib/Rules.Unix
RESTRICTED=	Legal status of distributed ROM images unclear
WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=	BPP8 BPP16 BPP24 BPP32 DOCS
OPTIONS_DEFAULT=	BPP32
BPP8_DESC=	With BPP8
BPP16_DESC=	With BPP16
BPP24_DESC=	With BPP24
BPP32_DESC=	With BPP32 (see pkg-message)

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/fMSX/Unix/Makefile \
		${WRKSRC}/EMULib/Rules.Unix
.if ${PORT_OPTIONS:MBPP32} || defined(PACKAGE_BUILDING) || defined(BATCH)
	${REINPLACE_CMD} -e 's/BPP16/BPP32/' ${WRKSRC}/fMSX/Unix/Makefile
.endif
.if ${PORT_OPTIONS:MBPP24}
	${REINPLACE_CMD} -e 's/BPP16/BPP24/' ${WRKSRC}/fMSX/Unix/Makefile
.endif
.if ${PORT_OPTIONS:MBPP16}
	${REINPLACE_CMD} -e 's/BPP16/BPP16/' ${WRKSRC}/fMSX/Unix/Makefile
.endif
.if ${PORT_OPTIONS:MBPP8}
	${REINPLACE_CMD} -e 's/BPP16/BPP8/' ${WRKSRC}/fMSX/Unix/Makefile
.endif

do-build:
	cd ${WRKSRC}/fMSX/Unix && ${MAKE_CMD} DEBUG_FLAGS=${DEBUG_FLAGS}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fmsx ${STAGEDIR}${PREFIX}/bin
	${REINPLACE_CMD} -i "" -e "s,PREFIX,${PREFIX},g" ${STAGEDIR}${PREFIX}/bin/fmsx
	${INSTALL_PROGRAM} ${WRKSRC}/fMSX/Unix/fmsx ${STAGEDIR}${PREFIX}/bin/fmsx.bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/fMSX/ROMs/*.FNT ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.ROM ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fMSX/*.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
