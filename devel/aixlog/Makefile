PORTNAME=	aixlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ logging library
WWW=		https://github.com/badaix/aixlog

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	badaix

CMAKE_OFF=	BUILD_EXAMPLE
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM:STRING=3.5 # CMake 4 compatibility, see https://github.com/badaix/aixlog/issues/25

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/aixlog.hpp

.include <bsd.port.mk>
