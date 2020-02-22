# Created by: Keith Walker <kew@icehouse.net>
# $FreeBSD$

PORTNAME=	sscalc
PORTVERSION=	1.0
CATEGORIES=	astro
MASTER_SITES=	https://opsec.eu/src/

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Sunrise and sunset time calculator

OPTIONS_DEFINE=	DOCS

pre-fetch:
.if !defined(LAT)
	@${ECHO_MSG} "Type \"make LAT=<nnn.nn> LON=<nnn.nn>\" to hardwire your site"
.else
	@${ECHO_MSG} "Compiling in lat/longs"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/sscalc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/sscalc.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cities.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
