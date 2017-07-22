# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libddoc
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/economicmodeling/libddoc/archive/
DISTNAME=	${DISTVERSION:S/^/v/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	D implementation of the DDoc macro system

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/libddoc.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
