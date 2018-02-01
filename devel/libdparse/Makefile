# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdparse
DISTVERSION=	0.8.0-alpha1
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Library for lexing and parsing D source code

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub

USE_GITHUB=	yes
GH_ACCOUNT=	dlang-community
GH_TAGNAME=	v${DISTVERSION:S/alpha/alpha./}
#GH_TAGNAME=	v${PORTVERSION}

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/libdparse.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
