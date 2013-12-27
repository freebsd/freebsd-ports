# Created by: dk
# $FreeBSD$

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
COMMENT=	Portable MSX/MSX2/MSX2+ Emulator

USE_XORG=	xi x11
USE_ZIP=	yes
USES=		gmake dos2unix
DOS2UNIX_FILES= EMULib/LibUnix.c EMULib/NetUnix.c EMULib/Rules.gcc \
		EMULib/Rules.Unix
RESTRICTED=	Legal status of distributed ROM images unclear
WRKSRC=		${WRKDIR}

BROKEN=		does not build

OPTIONS_DEFINE=	BPP8 BPP16 BPP24 BPP32 DOCS
OPTIONS_DEFAULT=	BPP32
BPP8_DESC=	With BPP8
BPP16_DESC=	With BPP16
BPP24_DESC=	With BPP24
BPP32_DESC=	With BPP32 (see pkg-message)

NO_STAGE=	yes
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
	cd ${WRKSRC}/fMSX/Unix && ${GMAKE}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fmsx ${PREFIX}/bin
	${REINPLACE_CMD} -i "" -e "s,PREFIX,${PREFIX},g" ${PREFIX}/bin/fmsx
	${INSTALL_PROGRAM} ${WRKSRC}/fMSX/Unix/fmsx ${PREFIX}/bin/fmsx.bin
	${MKDIR} ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/fMSX/ROMs/*.FNT ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.ROM ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/fMSX/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
