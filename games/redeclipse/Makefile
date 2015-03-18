# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	redeclipse
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_${PORTVERSION:C/^([0-9]+\.[0-9]+)\..*/\1/}
DISTNAME=	${PORTNAME}_${PORTVERSION}_nix

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single-player and multi-player first-person ego-shooter

LICENSE_COMB=	multi
LICENSE=	MIT ZLIB

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
USE_AUTOTOOLS=	aclocal automake autoconf:env
AUTOMAKE_ARGS=	-ia
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	libenet

SUB_FILES=	${PLIST_FILES:Mbin/*:T}

PORTDATA=	game data
PORTDOCS=	*
PLIST_DIRS=	%%DATADIR%%/data/brush

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=CLIENT DEDICATED OPTIMIZED_CFLAGS

CLIENT_DESC=	Build client
CLIENT_USE=			GL=gl SDL=image,mixer,sdl XORG=x11
CLIENT_ALL_TARGET=		client
CLIENT_PLIST_FILES=		bin/${PORTNAME} libexec/${PORTNAME} \
				share/pixmaps/${PORTNAME}.ico
DEDICATED_DESC=	Build dedicated server
DEDICATED_ALL_TARGET=		server
DEDICATED_PLIST_FILES=		bin/${PORTNAME}_server libexec/${PORTNAME}_server
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fomit-frame-pointer
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3 -fomit-frame-pointer

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64
.endif

.if ${PORT_OPTIONS:MCLIENT}
DESKTOP_ENTRIES="Red Eclipse" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;Shooter;" \
		""
.endif

do-install:
.for f in ${PLIST_FILES:Mbin/*}
	${INSTALL_SCRIPT} ${WRKDIR}/${f:T} ${STAGEDIR}${PREFIX}/${f}
.endfor
.for f in ${PLIST_FILES:Mlibexec/*}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f:T} \
		${STAGEDIR}${PREFIX}/${f:H}
.endfor
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps
.endif
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
