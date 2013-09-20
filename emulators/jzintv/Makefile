# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	jzintv
PORTVERSION=	1.0b4
CATEGORIES=	emulators
MASTER_SITES=	http://spatula-city.org/~im14u2c/intv/dl/
DISTFILES=	${PORTNAME}-1.0-beta4-src${EXTRACT_SUFX} \
		${PORTNAME}-1.0-beta4-sdk1600${EXTRACT_SUFX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Portable Intellivision(TM) Emulator

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/jzintv-1.0-beta4
BUILD_WRKSRC=	${WRKSRC}/src
USE_GMAKE=	yes
USE_XORG=	x11 xau xdmcp
USE_SDL=	sdl
USE_ZIP=	yes
CPPFLAGS+=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} `${SDL_CONFIG} --libs`

OPTIONS_DEFINE=	TOOLS
TOOLS_DESC=	Install additional tools

TOOLS=	as1600 bin2rom cgc_update crc32 dasm0256 dasm1600 dasm1600o dis1600 \
	frombit frombit_r fromhex gms2rom imvtogif imvtoppm rom2bin rom_merge \
	show_grom split_rom tobit tobit_f tobit_r tohex

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOOLS}
PLIST_SUB+=	PL_TOOLS=""
.else
PLIST_SUB+=	PL_TOOLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '288s|/usr/local/share/jzintv|${DATADIR}|' ${BUILD_WRKSRC}/config.h
	@${CP} ${BUILD_WRKSRC}/Makefile.freebsd ${BUILD_WRKSRC}/Makefile

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/rom

do-install:
	${MKDIR} ${DATADIR}/rom
	${INSTALL_DATA} ${WRKSRC}/rom/*.rom ${DATADIR}/rom/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jzintv ${PREFIX}/bin/jzintv
.if ${PORT_OPTIONS:MTOOLS}
.for tool in ${TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${PREFIX}/bin/jzintv-${tool}
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/doc
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/doc)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
