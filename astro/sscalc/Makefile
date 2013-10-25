# Created by: Keith Walker <kew@icehouse.net>
# $FreeBSD$

PORTNAME=	sscalc
PORTVERSION=	1.0
CATEGORIES=	astro
MASTER_SITES=	http://www.icehouse.net/kew/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sunrise and sunset time calculator

.include <bsd.port.options.mk>

pre-fetch:
.if !defined(LAT)
	@${ECHO_MSG} "Type \"make LAT=<nnn.nn> LON=<nnn.nn>\" to hardwire your site"
.else
	@${ECHO_MSG} "Compiling in lat/longs"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/sscalc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/sscalc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cities.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
