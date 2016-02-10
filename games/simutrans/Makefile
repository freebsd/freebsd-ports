# $FreeBSD$

PORTNAME=	simutrans
DISTVERSION=	120-1-3
CATEGORIES=	games
MASTER_SITES=	SF/simutrans/simutrans/${DISTVERSION} \
		SF/simutrans/pak64/${PAK64_SUBDIR}:pak64 \
		SF/simutrans/pak128/pak128%20for%20${PAK128_SUBDIR}:pak128
DISTFILES=	simutrans-src-${DISTVERSION}.zip \
		simulinux-i86-${DISTVERSION}.zip

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Transport Simulator

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/simutrans/license.txt

PAK64_DISTVERSION=	120-1-2
PAK64_SUBDIR=		120-1
PAK128_DISTVERSION=	2.6--ST120
PAK128_SUBDIR=		ST%20120%20%282.6%2C%20completed%20elevated%20tracks%29
SIMUTRANS_REVISION=	7753

OPTIONS_DEFINE= 	DOCS
OPTIONS_MULTI=		PAK
OPTIONS_MULTI_PAK=	PAK64 PAK128
OPTIONS_DEFAULT=	PAK64
PAK64_DESC=		Default graphics
PAK128_DESC=		High resolution graphics

# Threading disabled because FreeBSD does not have a static initializer
# for recursive mutexes.
MAKE_ARGS=	BACKEND=mixer_sdl \
		COLOUR_DEPTH=16 \
		MULTI_THREAD=0 \
		OSTYPE=freebsd \
		FLAGS="-DUSE_C -DREVISION=${SIMUTRANS_REVISION}" \
		VERBOSE=1
NO_WRKSUBDIR=	yes
USES=		dos2unix gmake zip
DOS2UNIX_FILES=	gui/loadsave_frame.h
USE_SDL=	sdl mixer

DESKTOP_ENTRIES=Simutrans "" "" simutrans "Game;Simulation;" false
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
	(cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} \
		"config font music script text themes" ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MPAK64}
	(cd ${WRKSRC}/simutrans && ${COPYTREE_SHARE} \
		pak ${STAGEDIR}${DATADIR})
.endif
.if ${PORT_OPTIONS:MPAK128}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pak128 ${STAGEDIR}${DATADIR})
.endif
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/simutrans/readme.txt ${STAGEDIR}${DATADIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/build/default/sim \
		${STAGEDIR}${PREFIX}/bin/simutrans-bin
	${INSTALL_SCRIPT} ${FILESDIR}/simutrans ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
