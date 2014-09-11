# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	bloodfrontier
DISTVERSION=	B2
PORTREVISION=	8
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
USE_XORG=	x11

ALL_TARGET=	libenet ${BINARIES}

SUB_FILES=	bfclient bfserver

PORTDATA=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS

CLIENT_DESC=	Build client
DEDICATED_DESC= Build dedicated server

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		yes
USE_SDL=	image mixer sdl
PLIST_FILES+=	bin/bfclient libexec/bfclient share/pixmaps/${PORTNAME}.ico
BINARIES+=	client

DESKTOP_ENTRIES="Blood Frontier" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"bfclient" \
		"Game;Shooter;" \
		""
.endif

.if ${PORT_OPTIONS:MDEDICATED}
PLIST_FILES+=	bin/bfserver libexec/bfserver
BINARIES+=	server
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer
CXXFLAGS+=	-O3 -fomit-frame-pointer
.endif

do-install:
.for f in ${BINARIES}
	${INSTALL_SCRIPT} ${WRKDIR}/bf${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bf${f} ${STAGEDIR}${PREFIX}/libexec
.endfor
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ico ${STAGEDIR}${PREFIX}/share/pixmaps
.endif
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} "." ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
