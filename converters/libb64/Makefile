# Created by: Ismail Yenigul <ismail.yenigul@surgate.com>
# $FreeBSD$

PORTNAME=	libb64
PORTVERSION=	1.2.1
CATEGORIES=	converters mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}

MAINTAINER=	ismail.yenigul@surgate.com
COMMENT=	Library for fast Base64 encoding and decoding

BUILD_DEPENDS=	makedepend:devel/makedepend

USES=		gmake zip
ALL_TARGET=	all_src
USE_LDCONFIG=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libb64.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libb64.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -fs libb64.so.0 ${STAGEDIR}${PREFIX}/lib/libb64.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/b64
	${INSTALL_DATA} ${WRKSRC}/include/b64/*.h \
		${STAGEDIR}${PREFIX}/include/b64

.include <bsd.port.mk>
