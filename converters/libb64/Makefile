# Created by: Ismail Yenigul <ismail.yenigul@surgate.com>
# $FreeBSD$

PORTNAME=	libb64
PORTVERSION=	1.2.1
CATEGORIES=	converters mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}

MAINTAINER=	ismail.yenigul@surgate.com
COMMENT=	Library of ANSI C routines for fast encoding/decoding data

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USES=		gmake zip
ALL_TARGET=	all_src
USE_LDCONFIG=	yes

BROKEN_powerpc=	Does not compile on powerpc

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libb64.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libb64.so.0 ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -fs libb64.so.0 libb64.so)
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/b64
	${INSTALL_DATA} ${WRKSRC}/include/b64/*.h ${STAGEDIR}${PREFIX}/include/b64

.include <bsd.port.mk>
