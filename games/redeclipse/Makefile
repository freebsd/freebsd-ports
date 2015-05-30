# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	redeclipse
PORTVERSION=	1.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single-player and multi-player first-person ego-shooter

LICENSE_COMB=	multi
LICENSE=	MIT ZLIB

RUN_DEPENDS=	redeclipse-data>=1.5.0:${PORTSDIR}/games/redeclipse-data

USE_GITHUB=	yes
GH_ACCOUNT=	red-eclipse
GH_PROJECT=	base

USES=		gmake
BUILD_WRKSRC=	${WRKSRC}/src
USE_GCC=	yes	# clang dies, see https://llvm.org/bugs/show_bug.cgi?id=23010

SUB_FILES=	${PLIST_FILES:Mbin/*:T}

PORTDOCS=	*
PORTDATA=	*

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

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fomit-frame-pointer -ffast-math
OPTIMIZED_CFLAGS_CXXFLAGS=	-O3 -fomit-frame-pointer -ffast-math

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

post-patch:
	@${REINPLACE_CMD} -e 's|CLIENT_PCH=.*|CLIENT_PCH=|' ${WRKSRC}/src/Makefile

do-install:
.for f in ${PLIST_FILES:Mbin/*}
	${INSTALL_SCRIPT} ${WRKDIR}/${f:T} ${STAGEDIR}${PREFIX}/${f}
.endfor
.for f in ${PLIST_FILES:Mlibexec/*}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f:T}_bsd \
		${STAGEDIR}${PREFIX}/${f}
.endfor
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps
.endif
	(cd ${WRKSRC} && ${COPYTREE_SHARE} config ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
