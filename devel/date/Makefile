# $FreeBSD$

PORTNAME=	date
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Date and time library based on the C++11/14/17 <chrono> header

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	HowardHinnant
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS BUILD_TZ_LIB
CMAKE_OFF=	ENABLE_DATE_TESTING

PLIST_FILES=	include/date/date.h \
		include/date/tz.h \
		lib/cmake/date/dateConfig.cmake \
		lib/cmake/date/dateConfigVersion.cmake \
		lib/cmake/date/dateTargets-${CMAKE_BUILD_TYPE:tl}.cmake \
		lib/cmake/date/dateTargets.cmake \
		lib/libdate-tz.so \
		lib/libdate-tz.so.2.4.1

do-test:
	@cd ${WRKSRC} && ${REINPLACE_CMD} 's|!/bin/bash|!${LOCALBASE}/bin/bash|' compile_fail.sh test_fail.sh
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DENABLE_DATE_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} testit

.include <bsd.port.mk>
