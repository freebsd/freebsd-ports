# $FreeBSD$

PORTNAME=	libspng
DISTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.com/randy408/libspng/uploads/3d980bac86c51368f40af2f1ac79a057/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple PNG decoding and encoding library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson pkgconfig tar:xz
USE_LDCONFIG=	yes

MESON_ARGS=	-Denable_opt=false
PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
