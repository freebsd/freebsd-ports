# New ports collection makefile for:	ephem
# Date created:		3 April 1997
# Whom:			eserte
#
# $FreeBSD$
#

PORTNAME=	ephem
PORTVERSION=	4.28
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}_${PORTVERSION}_unix

MAINTAINER=	eserte@cs.tu-berlin.de
COMMENT=	An interactive terminal-based astronomical ephemeris program

NO_WRKSUBDIR=	yes
ALL_TARGET=

CFLAGS+=	-Wno-implicit

do-install:
	-cd ${WRKSRC}; \
	${INSTALL_PROGRAM} ephem ${PREFIX}/bin; \
	${MKDIR} ${PREFIX}/share/ephem; \
	${INSTALL_DATA} Man.txt ${PREFIX}/share/ephem/; \
	[ ! -f ${PREFIX}/share/ephem/ephem.db ] && ${INSTALL_DATA} ephem.db ${PREFIX}/share/ephem/; \
	[ ! -f ${PREFIX}/share/ephem/ephem.cfg ] && ${INSTALL_DATA} ephem.cfg ${PREFIX}/share/ephem/

post-install:
	@${ECHO_MSG} Don\'t forget to edit ${PREFIX}/share/ephem/ephem.cfg!

.include <bsd.port.mk>
