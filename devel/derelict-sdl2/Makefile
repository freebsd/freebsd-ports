PORTNAME=	derelict-sdl2
PORTVERSION=	2.1.4
PORTREVISION=	8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Dynamic bindings to SDL2 and its libraries for the D lang
WWW=		https://github.com/DerelictOrg/DerelictSDL2

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libDerelictUtil.a:devel/derelict-util

USES=		dos2unix
USE_GITHUB=	yes
GH_ACCOUNT=	DerelictOrg
GH_PROJECT=	DerelictSDL2

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d
DC=		${PREFIX}/bin/ldmd2

post-patch:
	${REINPLACE_CMD} -e '13,15d' ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && \
		${SETENV} DUB_HOME=${WRKDIR}/dub_home DC=${DC} ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libDerelictSDL2.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/source && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
