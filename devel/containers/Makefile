# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	containers
DISTVERSION=	0.8.0-alpha.11
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Containers backed on dlang by std.experimental.allocator

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libmir-core.a:devel/mir-core \
		${LOCALBASE}/lib/d/libstdx-allocator.a:devel/stdx-allocator

USE_GITHUB=	yes
GH_ACCOUNT=	economicmodeling

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dub.json

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/libemsi_containers.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
