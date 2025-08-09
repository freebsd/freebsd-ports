PORTNAME=	spdlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.2
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Super fast C++ logging library
WWW=		https://github.com/gabime/spdlog

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

post-stage:
# let consumers know that this package was compiled with SPDLOG_FMT_EXTERNAL=yes
	${ECHO_CMD} '#define SPDLOG_FMT_EXTERNAL' >> ${STAGEDIR}${PREFIX}/include/spdlog/tweakme.h

.include <bsd.port.mk>
