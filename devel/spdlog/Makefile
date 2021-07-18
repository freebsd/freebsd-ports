# Created by: vanilla@

PORTNAME=	spdlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.5
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/gabime/spdlog/commit/
PATCHFILES=	7b14a65b2b8cbdca3c6bd1d36fe5b271389c1d07.patch:-p1 \
		68111122086187761cca36c24e6d8c8daa96656d.patch:-p1

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Super fast C++ logging library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt

USES=		cmake compiler:c++11-lib pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	gabime
USE_LDCONFIG=	yes
CMAKE_ON=	SPDLOG_BUILD_SHARED SPDLOG_FMT_EXTERNAL
CMAKE_OFF=	SPDLOG_BUILD_BENCH
PLIST_SUB=	SOVERSION="${DISTVERSION}"

post-extract:
	${RM} -r ${WRKSRC}/include/spdlog/fmt/bundled

post-patch:
	${RM} ${WRKSRC}/include/spdlog/fmt/*.h.orig

.include <bsd.port.mk>
