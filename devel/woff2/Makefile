PORTNAME=	woff2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	devel

PATCH_SITES=	https://github.com/google/${PORTNAME}/commit/
PATCHFILES=	3831354113db8803fb1f5ba196cf0bbb537578dd.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and converter tools for the WOFF 2.0 web font format
WWW=		https://github.com/google/woff2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli

USES=		cmake compiler:c++11-lib pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIBVER=${DISTVERSION}

CMAKE_ON=	CMAKE_SKIP_RPATH

.include <bsd.port.mk>
