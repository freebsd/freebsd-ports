# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	bloodfrontier
DISTVERSION=	B2
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blood%20Frontier%20Beta%202
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single- and multi-player first-person shooter based on Cube 2

LICENSE=	ZLIB

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	libenet

SUB_FILES=	${PLIST_FILES:Mbin/*:T}

PORTDATA=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS

CLIENT_DESC=	Build client
CLIENT_USE=			GL=gl SDL=image,mixer,sdl XORG=x11
CLIENT_ALL_TARGET=		client
CLIENT_PLIST_FILES=		bin/bfclient libexec/bfclient \
				share/pixmaps/${PORTNAME}.ico
DEDICATED_DESC= Build dedicated server
DEDICATED_PLIST_FILES=		bin/bfserver libexec/bfserver
DEDICATED_ALL_TARGET=		server
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fomit-frame-pointer
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3 -fomit-frame-pointer

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${PORT_OPTIONS:MCLIENT}
DESKTOP_ENTRIES="Blood Frontier" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"bfclient" \
		"Game;Shooter;" \
		""
.endif

do-install:
.for f in ${PLIST_FILES:Mbin/*}
	${INSTALL_SCRIPT} ${WRKDIR}/${f:T} ${STAGEDIR}${PREFIX}/${f}
.endfor
.for f in ${PLIST_FILES:Mlibexec/*}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f:T} ${STAGEDIR}${PREFIX}/${f:H}
.endfor
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps
.endif
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "." ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
