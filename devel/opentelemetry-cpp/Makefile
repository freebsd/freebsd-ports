PORTNAME=	opentelemetry-cpp
PORTVERSION=	1.23.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenTelemetry C++ client
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-cpp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgtest.so:devel/googletest

USES=		cpe cmake:testing compiler:c++14-lang

CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_TESTING
CMAKE_ON=	BUILD_SHARED_LIBS \
		CMAKE_POSITION_INDEPENDENT_CODE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	open-telemetry

CPE_VENDOR=	cncf

.include <bsd.port.mk>
