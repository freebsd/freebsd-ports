# Created by: Johan Str??m <johan@stromnet.se>
# $FreeBSD$

PORTNAME=	jsoncpp
PORTVERSION=	1.8.1
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON reader and writer library for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	open-source-parsers

USES=		compiler:c++11-lang dos2unix scons
USE_LDCONFIG=	yes

PLATFORM=	linux-gcc-FreeBSD
MAKE_ARGS=	platform=${PLATFORM}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/jsoncpp
	(cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} json/ ${STAGEDIR}${PREFIX}/include/jsoncpp/)
	${INSTALL_DATA} ${WRKSRC}/libs/${PLATFORM}/libjsoncpp.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libs/${PLATFORM}/libjsoncpp.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${LN} -s libjsoncpp.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libjsoncpp.so.1
	${LN} -s libjsoncpp.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libjsoncpp.so
	${CP} ${WRKSRC}/pkg-config/jsoncpp.pc.in ${STAGEDIR}${PREFIX}/libdata/pkgconfig/jsoncpp.pc
	@${REINPLACE_CMD} -i '' \
		-e 's|@CMAKE_INSTALL_FULL_LIBDIR@|${PREFIX}/lib|g' \
		-e 's|@CMAKE_INSTALL_FULL_INCLUDEDIR@|${PREFIX}/include/jsoncpp|g' \
		-e 's|@JSONCPP_VERSION@|${DISTVERSION}|g' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/jsoncpp.pc

do-test:
	@${ECHO} "Please note that 3 testcases are known to fail: https://github.com/open-source-parsers/jsoncpp/issues/628"
	@cd ${WRKSRC} && CXX=${CXX} ${SCONS} platform=${PLATFORM} check

.include <bsd.port.mk>
