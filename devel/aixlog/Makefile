# $FreeBSD$

PORTNAME=	aixlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ logging library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	badaix

CMAKE_OFF=	BUILD_EXAMPLE

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/aixlog.hpp

.include <bsd.port.mk>
