# Created by: eserte
# $FreeBSD$

PORTNAME=	ephem
PORTVERSION=	4.28
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}_${PORTVERSION}_unix

MAINTAINER=	slaven@rezic.de
COMMENT=	An interactive terminal-based astronomical ephemeris program

NO_STAGE=	yes
NO_WRKSUBDIR=	yes
ALL_TARGET=

CFLAGS+=	-Wno-implicit

USE_GCC=	any

do-install:
	-cd ${WRKSRC}; \
	${INSTALL_PROGRAM} ephem ${STAGEDIR}${PREFIX}/bin; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ephem; \
	${INSTALL_DATA} Man.txt ${STAGEDIR}${PREFIX}/share/ephem/; \
	[ ! -f ${STAGEDIR}${PREFIX}/share/ephem/ephem.db ] && ${INSTALL_DATA} ephem.db ${STAGEDIR}${PREFIX}/share/ephem/; \
	[ ! -f ${STAGEDIR}${PREFIX}/share/ephem/ephem.cfg ] && ${INSTALL_DATA} ephem.cfg ${STAGEDIR}${PREFIX}/share/ephem/

post-install:
	@${ECHO_MSG} Don\'t forget to edit ${PREFIX}/share/ephem/ephem.cfg!

.include <bsd.port.mk>
