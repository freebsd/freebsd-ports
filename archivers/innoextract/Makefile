PORTNAME=	innoextract
DISTVERSION=	1.9-82
DISTVERSIONSUFFIX=	-g6e9e34e
CATEGORIES=	archivers

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Program to extract Inno Setup files
WWW=		https://constexpr.org/innoextract/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang iconv localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	dscharrer
CMAKE_ON=	Boost_USE_STATIC_LIBS

PLIST_FILES=	bin/innoextract \
		share/man/man1/innoextract.1.gz

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check

.include <bsd.port.mk>
