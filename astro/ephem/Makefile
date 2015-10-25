# Created by: eserte
# $FreeBSD$

PORTNAME=	ephem
PORTVERSION=	4.28
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	LOCAL/trevor
DISTNAME=	${PORTNAME}_${PORTVERSION}_unix

MAINTAINER=	slaven@rezic.de
COMMENT=	Interactive terminal-based astronomical ephemeris program

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
NO_WRKSUBDIR=	yes
ALL_TARGET=

CFLAGS+=	-Wno-implicit -Wno-return-type

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ephem ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Man.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ephem.cfg ${STAGEDIR}${DATADIR}/ephem.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/ephem.db ${STAGEDIR}${DATADIR}/ephem.db.sample

post-install:
	@${ECHO_MSG} "Don't forget to edit ${PREFIX}/share/ephem/ephem.cfg!"

.include <bsd.port.mk>
