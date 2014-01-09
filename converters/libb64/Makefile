# Created by: Ismail Yenigul <ismail.yenigul@surgate.com>
# $FreeBSD$

PORTNAME=	libb64
PORTVERSION=	1.2
CATEGORIES=	converters mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=	.zip

MAINTAINER=	ismail.yenigul@surgate.com
COMMENT=	Library of ANSI C routines for fast encoding/decoding data

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

BROKEN_powerpc=	Does not compile on powerpc

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libb64.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/b64
	${INSTALL_DATA} ${WRKSRC}/include/b64/*.h ${STAGEDIR}${PREFIX}/include/b64

.include <bsd.port.mk>
