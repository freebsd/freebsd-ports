PORTNAME=	opentelemetry-cpp
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	OpenTelemetry C++ client
WWW=		https://github.com/open-telemetry/opentelemetry-cpp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	open-telemetry
GH_PROJECT=	${PORTNAME}

USES=		cmake compiler:c++14-lang

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON
CMAKE_OFF=	BUILD_TESTING BUILD_EXAMPLES

LIB_DEPENDS=	libgtest.so:devel/googletest \
		libcurl.so:ftp/curl

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	SHLIBVER=${PORTVERSION}

.include <bsd.port.mk>
