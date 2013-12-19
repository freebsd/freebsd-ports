# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	redeclipse
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_${PORTVERSION:C/^([0-9]+\.[0-9]+)\..*/\1/}
DISTNAME=	${PORTNAME}_${PORTVERSION}_nix

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single-player and multi-player first-person ego-shooter

LICENSE_COMB=	multi
LICENSE=	MIT ZLIB

MANUAL_PACKAGE_BUILD=	huge

USES=		gmake
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
USE_AUTOTOOLS=	aclocal automake autoconf:env
AUTOMAKE_ARGS=	-ia
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	libenet

SUB_FILES=	${PORTNAME} ${PORTNAME}_server

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=CLIENT DEDICATED OPTIMIZED_CFLAGS

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		yes
USE_SDL=	image mixer sdl
PLIST_FILES+=	bin/${PORTNAME} libexec/${PORTNAME} share/pixmaps/${PORTNAME}.ico
BINARIES+=	${PORTNAME}
ALL_TARGET+=	client

DESKTOP_ENTRIES="Red Eclipse" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Game;Shooter;" \
		""
.endif

.if ${PORT_OPTIONS:MDEDICATED}
PLIST_FILES+=	bin/${PORTNAME}_server libexec/${PORTNAME}_server
BINARIES+=	${PORTNAME}_server
ALL_TARGET+=	server
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer
CXXFLAGS+=	-O3 -fomit-frame-pointer
.endif

do-install:
.for f in ${BINARIES}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f} ${STAGEDIR}${PREFIX}/libexec
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "game data" ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ico ${STAGEDIR}${PREFIX}/share/pixmaps/
.endif

.include <bsd.port.mk>
