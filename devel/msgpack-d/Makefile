# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msgpack-d
DISTVERSION=	1.0.0-beta8
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Pure D implementation of MessagePack

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub

USE_GITHUB=	yes
GH_ACCOUNT=	msgpack
# FIXME: Remove this once it goes out of beta.
# Side note, 1.0.0-beta.6 was a perfectly reasonable version to be used in
# DISTVERSION.
GH_TAGNAME=	v${DISTVERSION:S/beta/beta./}

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/libmsgpack-d.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
