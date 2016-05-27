# Created by: Johan Str??m <johan@stromnet.se>
# $FreeBSD$

PORTNAME=	jsoncpp
DISTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	JSON reader and writer library for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	open-source-parsers

USES=		dos2unix scons
USE_LDCONFIG=	yes

MAKE_ARGS=	platform=linux-gcc

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
# NOTE Certain newest compiler features unlock some parts of jsoncpp API (ex. see JSON_HAS_RVALUE_REFERENCES).
# Use c++11 above to be most inclusive.
USES+=		compiler:c++11-lang
CXXFLAGS+=	--std=c++11
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/jsoncpp
	(cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} json/ ${STAGEDIR}${PREFIX}/include/jsoncpp/)
	${INSTALL_DATA} ${WRKSRC}/libs/linux-gcc-FreeBSD/libjsoncpp.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libs/linux-gcc-FreeBSD/libjsoncpp.so.${DISTVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${LN} -s libjsoncpp.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libjsoncpp.so.1
	${LN} -s libjsoncpp.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libjsoncpp.so
	${CP} ${WRKSRC}/pkg-config/jsoncpp.pc.in ${STAGEDIR}${PREFIX}/libdata/pkgconfig/jsoncpp.pc
	@${REINPLACE_CMD} -i '' \
		-e 's|@CMAKE_INSTALL_PREFIX@|${PREFIX}|g' \
		-e 's|@LIBRARY_INSTALL_DIR@|${PREFIX}/lib|g' \
		-e 's|@INCLUDE_INSTALL_DIR@|${PREFIX}/include/jsoncpp|g' \
		-e 's|@JSONCPP_VERSION@|${DISTVERSION}|g' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/jsoncpp.pc

.include <bsd.port.post.mk>
