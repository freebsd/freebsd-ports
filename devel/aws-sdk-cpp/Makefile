# $FreeBSD$

PORTNAME=	aws-sdk-cpp
PORTVERSION=	1.0.117
CATEGORIES=	devel

MAINTAINER=	arved@FreeBSD.org
COMMENT=	C++11 interface for Amazon Web Services (AWS)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

BROKEN_aarch64=		fails to build: runaway process
BROKEN_armv6=		fails to build: runaway process
BROKEN_powerpc64=	fails to build: runaway process

USE_GITHUB=	yes
GH_ACCOUNT=	aws
USES=		cmake pkgconfig compiler:c++11-lib ssl
USE_LDCONFIG=	yes
CXXFLAGS=	-Wno-error

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,/pkgconfig,/../libdata/pkgconfig,g" \
		${WRKSRC}/aws-cpp-sdk-core/CMakeLists.txt \
		${WRKSRC}/cmake/utilities.cmake

.include <bsd.port.post.mk>
