# $FreeBSD$

PORTNAME=	aws-sdk-cpp
PORTVERSION=	1.4.14
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++11 interface for Amazon Web Services (AWS)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_12=	C++ error: https://github.com/aws/aws-sdk-cpp/issues/825
BROKEN_aarch64=		fails to build: runaway process
BROKEN_armv6=		fails to build: runaway process
BROKEN_armv7=		fails to build: runaway process
BROKEN_powerpc64=	fails to build: runaway process

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake pkgconfig compiler:c++11-lib ssl
USE_GITHUB=	yes
GH_ACCOUNT=	aws
USE_LDCONFIG=	yes
CXXFLAGS=	-Wno-error -Wno-c11-extensions

post-patch:
	${REINPLACE_CMD} -e "s,/pkgconfig,/../libdata/pkgconfig,g" \
		${WRKSRC}/aws-cpp-sdk-core/CMakeLists.txt \
		${WRKSRC}/cmake/utilities.cmake

.include <bsd.port.mk>
