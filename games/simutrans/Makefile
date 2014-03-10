# $FreeBSD$

PORTNAME=	simutrans
DISTVERSION=	112-3
CATEGORIES=	games
MASTER_SITES=	SF/simutrans/simutrans/${DISTVERSION} \
		SF/simutrans/pak64/${PAK64_DISTVERSION}:pak64 \
		SF/simutrans/pak128/pak128%20for%20${PAK128_SUBDIR}:pak128
DISTFILES=	simutrans-src-${DISTVERSION}.zip \
		simulinux-${DISTVERSION}.zip

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Transport Simulator

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/simutrans/license.txt

PAK64_DISTVERSION=	${DISTVERSION}
PAK128_DISTVERSION=	2.3.0--112.2
PAK128_SUBDIR=		112-2
SIMUTRANS_REVISION=	6520

OPTIONS_DEFINE= 	DOCS
OPTIONS_MULTI=		PAK
OPTIONS_MULTI_PAK=	PAK64 PAK128
OPTIONS_DEFAULT=	PAK64
PAK64_DESC=		Default graphics
PAK128_DESC=		High resolution graphics

MAKE_ARGS=	BACKEND=mixer_sdl \
		COLOUR_DEPTH=16 \
		OSTYPE=freebsd \
		FLAGS="-DUSE_C -DREVISION=${SIMUTRANS_REVISION}" \
		VERBOSE=1
NO_WRKSUBDIR=	yes
USES=		gmake zip
USE_SDL=	sdl mixer

DESKTOP_ENTRIES=Simutrans "" "" simutrans "Game;Simulation;" "false"
PLIST_FILES=	bin/simutrans bin/simutrans-bin
PORTDATA=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAK64}
DISTFILES+=	simupak64-${PAK64_DISTVERSION}.zip:pak64
.endif

.if ${PORT_OPTIONS:MPAK128}
DISTFILES+=	pak128-${PAK128_DISTVERSION}.zip:pak128
.endif

post-patch:
	@${REINPLACE_CMD} 's/-O[^ ]*//' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/simutrans/.simutrans/' ${WRKSRC}/simsys.cc

do-install:
	cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} \
		"config font music script skin text" ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MPAK64}
	cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} pak ${STAGEDIR}${DATADIR}
.endif
.if ${PORT_OPTIONS:MPAK128}
	cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} pak128 ${STAGEDIR}${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/simutrans/readme.txt ${STAGEDIR}${DATADIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/build/default/sim \
		${STAGEDIR}${PREFIX}/bin/simutrans-bin
	${INSTALL_SCRIPT} ${FILESDIR}/simutrans ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
