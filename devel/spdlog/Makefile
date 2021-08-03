# Created by: vanilla@

PORTNAME=	spdlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/gabime/spdlog/commit/
PATCHFILES=	6faa5fc95b4be3aa5161c25e5b68155a644dc358.patch:-p1

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
