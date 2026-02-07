PORTNAME=	derelict-gl3
PORTVERSION=	1.0.24
PORTREVISION=	6
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Dynamic binding to OpenGL for the D Programming Language
WWW=		https://github.com/DerelictOrg/DerelictGL3

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libDerelictUtil.a:devel/derelict-util

USE_GITHUB=	yes
GH_ACCOUNT=	DerelictOrg
GH_PROJECT=	DerelictGL3

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d
DC=		${PREFIX}/bin/ldmd2

post-patch:
	@${REINPLACE_CMD} -e '13,15d' ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && \
		${SETENV} DUB_HOME=${WRKDIR}/dub_home DC=${DC} ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libDerelictGL3.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/source && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
