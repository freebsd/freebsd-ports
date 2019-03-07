# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	derelict-gl3
PORTVERSION=	1.0.24
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Dynamic binding to OpenGL for the D Programming Language

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

post-patch:
	@${REINPLACE_CMD} -e '13,15d' ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libDerelictGL3.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/source && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
