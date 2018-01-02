# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	redeclipse
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single-player and multi-player first-person ego-shooter

LICENSE=	MIT ZLIB
LICENSE_COMB=	multi

BROKEN_sparc64=	does not build on sparc64

RUN_DEPENDS=	redeclipse-data>=${PORTVERSION}:games/redeclipse-data

USE_GITHUB=	yes
GH_ACCOUNT=	red-eclipse
GH_PROJECT=	base

USES=		gmake
BUILD_WRKSRC=	${WRKSRC}/src

SUB_FILES=	${PLIST_FILES:Mbin/*:T}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS DOCS
OPTIONS_MULTI=		COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS

CLIENT_DESC=		Build client
CLIENT_USE=		GL=gl SDL=image2,mixer2,sdl2 XORG=x11
CLIENT_ALL_TARGET=	client
CLIENT_PLIST_FILES=	bin/${PORTNAME} libexec/${PORTNAME} \
			share/pixmaps/${PORTNAME}.ico
CLIENT_DESKTOP_ENTRIES=	"Red Eclipse" \
			"" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
			"${PORTNAME}" \
			"Game;Shooter;" \
			""

DEDICATED_DESC=		Build dedicated server
DEDICATED_ALL_TARGET=	server
DEDICATED_PLIST_FILES=	bin/${PORTNAME}_server libexec/${PORTNAME}_server

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fomit-frame-pointer -ffast-math
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3 -fomit-frame-pointer -ffast-math

post-extract:
	@${RM} -rf ${WRKSRC}/src/include ${WRKSRC}/src/lib

post-patch:
	@${REINPLACE_CMD} -e 's|CLIENT_PCH=.*|CLIENT_PCH=|' ${WRKSRC}/src/Makefile

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} config ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-CLIENT-on:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME}_bsd ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DEDICATED-on:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_server ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME}_server_bsd ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}_server

.include <bsd.port.mk>
