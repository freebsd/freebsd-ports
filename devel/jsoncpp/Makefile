# Created by: Johan Str??m <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	jsoncpp
DISTVERSION=	0.6.0-rc2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/jsoncpp/${DISTVERSION}
DISTNAME=	jsoncpp-src-${DISTVERSION}

MAINTAINER=	johan@stromnet.se
COMMENT=	JSON reader and writer library for C++

LICENSE=	MIT

USES=		dos2unix scons
USE_LDCONFIG=	yes

MAKE_ARGS=	platform=linux-gcc

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|' ${WRKSRC}/SConstruct

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/jsoncpp
	(cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} json/ ${STAGEDIR}${PREFIX}/include/jsoncpp/)
	(cd ${WRKSRC}/libs/linux-gcc-FreeBSD/ &&  \
		${INSTALL_LIB} libjson_linux-gcc-FreeBSD_libmt.a \
		${STAGEDIR}${PREFIX}/lib/libjsoncpp.a)
	(cd ${WRKSRC}/libs/linux-gcc-FreeBSD/ && \
		${INSTALL_LIB} libjson_linux-gcc-FreeBSD_libmt.so \
		${STAGEDIR}${PREFIX}/lib/libjsoncpp.so.0)
	(cd ${STAGEDIR}${PREFIX}/lib/ && ${LN} -s libjsoncpp.so.0 libjsoncpp.so )

.include <bsd.port.mk>
