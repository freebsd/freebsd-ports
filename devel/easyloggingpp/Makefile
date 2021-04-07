PORTNAME=	easyloggingpp
DISTVERSIONPREFIX=	v
DISTVERSION=	9.97.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ logging library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes
CMAKE_ON=	build_shared_lib  # patched in, requested such option in https://github.com/muflihun/easyloggingpp/issues/603

USE_GITHUB=	yes
GH_ACCOUNT=	amrayn

PLIST_FILES=	include/easylogging++.h \
		include/easylogging++.cc \
		lib/libeasyloggingpp.so \
		libdata/pkgconfig/easyloggingpp.pc

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dtest:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
