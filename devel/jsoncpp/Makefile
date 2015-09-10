# Created by: Johan Str??m <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	jsoncpp
DISTVERSION=	0.6.0-rc2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/jsoncpp/${DISTVERSION}
DISTNAME=	jsoncpp-src-${DISTVERSION}

MAINTAINER=	johan@stromnet.se
COMMENT=	JSON reader and writer library for C++

LICENSE=	MIT

USES=		dos2unix scons
USE_LDCONFIG=	yes

MAKE_ARGS=	platform=linux-gcc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/jsoncpp
	(cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} json/ ${STAGEDIR}${PREFIX}/include/jsoncpp/)
	${INSTALL_DATA} ${WRKSRC}/libs/linux-gcc-FreeBSD/libjsoncpp.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libs/linux-gcc-FreeBSD/libjsoncpp.so.0.6.0 \
		${STAGEDIR}${PREFIX}/lib
	${LN} -s libjsoncpp.so.0.6.0 ${STAGEDIR}${PREFIX}/lib/libjsoncpp.so.0
	${LN} -s libjsoncpp.so.0.6.0 ${STAGEDIR}${PREFIX}/lib/libjsoncpp.so

.include <bsd.port.mk>
