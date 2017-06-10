# $FreeBSD$

PORTNAME=	libtrue
PORTVERSION=	20170609
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	You can't handle the truth

USE_GITHUB=	yes
GH_ACCOUNT=	libtrue
GH_TAGNAME=	cc8c99f5d1406b5e7db7d712aff2b6b294560ace

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib ${STAGEDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/libtrue/libtrue.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libtrue/libtrue.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libtrue/libtrue.so.0 ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/true/true ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libtrue/true.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
