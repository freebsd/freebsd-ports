PORTNAME=	libertiff
PORTVERSION=	0.0.0.20250111
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++11 simple, header-only, TIFF reader
WWW=		https://github.com/libertiff/libertiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	googletest>=1.12.1:devel/googletest

USES=		cmake:testing compiler:c++11-lang

CMAKE_ON=	USE_EXTERNAL_GTEST
NO_ARCH=	yes

PLIST_FILES=	include/libertiff.hpp

USE_GITHUB=	yes
GH_TAGNAME=	7fc74e7

.include <bsd.port.mk>
