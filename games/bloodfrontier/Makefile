# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	bloodfrontier
DISTVERSION=	B2
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blood%20Frontier%20Beta%202
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single- and multi-player first-person shooter based on Cube 2

LICENSE=	ZLIB

BROKEN_powerpc=		fails to compile
BROKEN_powerpc64=	fails to compile: tools.h: incompatible types in assignment
BROKEN_sparc64=		fails to compile

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	libenet

CXXFLAGS+=	-Wno-c++11-narrowing

SUB_FILES=	${PLIST_FILES:Mbin/*:T}

PORTDATA=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS

CLIENT_DESC=		Build client
CLIENT_USES=		gl sdl xorg
CLIENT_USE=		GL=gl SDL=image,mixer,sdl XORG=x11
CLIENT_ALL_TARGET=	client
CLIENT_PLIST_FILES=	bin/bfclient libexec/bfclient \
			share/pixmaps/${PORTNAME}.ico

CLIENT_DESKTOP_ENTRIES=	"Blood Frontier" \
			"" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
			"bfclient" \
			"Game;Shooter;" \
			""
DEDICATED_DESC=		Build dedicated server
DEDICATED_PLIST_FILES=	bin/bfserver libexec/bfserver
DEDICATED_ALL_TARGET=	server

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fomit-frame-pointer
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3 -fomit-frame-pointer

do-install:
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "." ${STAGEDIR}${DATADIR})

do-install-CLIENT-on:
	${INSTALL_SCRIPT} ${WRKDIR}/bfclient ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bfclient ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DEDICATED-on:
	${INSTALL_SCRIPT} ${WRKDIR}/bfserver ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bfserver ${STAGEDIR}${PREFIX}/libexec/

.include <bsd.port.mk>
