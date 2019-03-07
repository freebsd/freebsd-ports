# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlib
PORTVERSION=	0.15.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Math, XML, I/O streams, image and audio processing for D

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub

USE_GITHUB=	yes
GH_ACCOUNT=	gecko0307

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/libdlib.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR}/${PORTNAME} "-name *\.d"

.include <bsd.port.mk>
