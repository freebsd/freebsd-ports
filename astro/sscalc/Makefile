# New ports collection makefile for: 	sscalc
# Date created:				Wed Nov 29 15:08:00 PST 2000
# Whom:					Keith Walker <kew@icehouse.net>
#
# $FreeBSD$
#

PORTNAME=	sscalc
PORTVERSION=	1.0
CATEGORIES=	astro
MASTER_SITES=	http://www.icehouse.net/kew/

MAINTAINER=	kew@icehouse.net

pre-fetch:
.if !defined(LAT)
	@${ECHO_MSG} "Type \"make LAT=<nnn.nn> LON=<nnn.nn>\" to hardwire your site"
.else
	@${ECHO_MSG} "Compiling in lat/longs"
.endif

post-install:
	@strip ${PREFIX}/bin/sscalc
	@${MKDIR} ${PREFIX}/share/doc/sscalc
	${INSTALL_DATA} ${WRKSRC}/cities.txt ${PREFIX}/share/doc/sscalc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sscalc

.include <bsd.port.mk>
