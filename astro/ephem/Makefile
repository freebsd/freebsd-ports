# New ports collection makefile for:	ephem
# Version required:	4.28
# Date created:		3 April 1997
# Whom:			eserte
#
# $FreeBSD$
#

DISTNAME=	ephem_4.28_unix
PKGNAME=	ephem-4.28
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	eserte@cs.tu-berlin.de

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
