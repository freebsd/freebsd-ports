PORTNAME=	spdlog
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Super fast C++ logging library
WWW=		https://github.com/gabime/spdlog

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++14-lang pathfix
.if make(test)
USES+=		pkgconfig
.endif
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gabime

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/include/spdlog/fmt/bundled

PLIST_SUB=	SOVERSION="${DISTVERSION}"

CMAKE_TESTING_ON=	SPDLOG_BUILD_TESTS

CMAKE_ON=	SPDLOG_BUILD_SHARED \
		SPDLOG_FMT_EXTERNAL
CMAKE_OFF=	SPDLOG_BUILD_BENCH

post-stage:
# let consumers know that this package was compiled with SPDLOG_FMT_EXTERNAL=yes
	${ECHO_CMD} '#define SPDLOG_FMT_EXTERNAL' >> ${STAGEDIR}${PREFIX}/include/spdlog/tweakme.h

.include <bsd.port.mk>
