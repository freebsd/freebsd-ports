# $FreeBSD$

PORTNAME=	woff2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Font compression reference code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	google

PLIST_SUB=	SHLIBVER=${DISTVERSION}

.include <bsd.port.mk>
