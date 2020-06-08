# Created by: vanilla@
# $FreeBSD$

PORTNAME=	spdlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	devel

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Super fast C++ logging library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt

USES=		cmake compiler:c++11-lib pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	gabime
CMAKE_ON=	SPDLOG_BUILD_SHARED SPDLOG_FMT_EXTERNAL
CMAKE_OFF=	SPDLOG_BUILD_BENCH

post-extract:
	${RM} -r ${WRKSRC}/include/spdlog/fmt/bundled

post-patch:
	${RM} ${WRKSRC}/include/spdlog/fmt/*.h.orig

.include <bsd.port.mk>
