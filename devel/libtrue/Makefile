# $FreeBSD$

PORTNAME=	libtrue
PORTVERSION=	20170609
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	You can't handle the truth

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	The joke is dead
EXPIRATION_DATE=2019-11-21

USE_GITHUB=	yes
GH_TAGNAME=	cc8c99f5d1406b5e7db7d712aff2b6b294560ace

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib ${STAGEDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/libtrue/libtrue.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libtrue/libtrue.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libtrue/libtrue.so.0 ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/true/true ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libtrue/true.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
