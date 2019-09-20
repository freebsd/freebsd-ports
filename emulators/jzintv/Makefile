# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	jzintv
PORTVERSION=	1.0b4
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://spatula-city.org/~im14u2c/intv/dl/
DISTFILES=	${PORTNAME}-1.0-beta4-src${EXTRACT_SUFX} \
		${PORTNAME}-1.0-beta4-sdk1600${EXTRACT_SUFX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Portable Intellivision(TM) Emulator

LICENSE=	GPLv2

USES=		alias gmake sdl xorg zip
USE_XORG=	x11 xau xdmcp
USE_SDL=	sdl

CPPFLAGS+=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib `${SDL_CONFIG} --libs` -lm
WRKSRC=		${WRKDIR}/jzintv-1.0-beta4
BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	TOOLS DOCS EXAMPLES
OPTIONS_SUB=	yes
TOOLS_DESC=	Install additional tools

TOOLS=	as1600 bin2rom cgc_update crc32 dasm0256 dasm1600 dasm1600o dis1600 \
	frombit frombit_r fromhex gms2rom imvtogif imvtoppm rom2bin rom_merge \
	show_grom split_rom tobit tobit_f tobit_r tohex

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} '288s|/usr/local/share/jzintv|${DATADIR}|' ${BUILD_WRKSRC}/config.h
	@${CP} ${BUILD_WRKSRC}/Makefile.freebsd ${BUILD_WRKSRC}/Makefile

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/rom

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/rom
	${INSTALL_DATA} ${WRKSRC}/rom/*.rom ${STAGEDIR}${DATADIR}/rom/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jzintv ${STAGEDIR}${PREFIX}/bin/jzintv
.for tool in ${TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${STAGEDIR}${PREFIX}/bin/jzintv-${tool}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/doc)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
