# New ports collection makefile for:	sim4
# Date created:		27 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	sim4
PORTVERSION=	2002.03.03
CATEGORIES=	biology
MASTER_SITES=	http://globin.cse.psu.edu/ftp/dist/sim4/
DISTNAME=	${PORTNAME}.${PORTVERSION:S/./-/g}

MAINTAINER=	bio@freebsd.net

WRKSRC=		${WRKDIR}/sim4.${PORTVERSION:S/./-/g}

ALL_TARGET=	sim4

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/sim4 ${PREFIX}/bin

.include <bsd.port.mk>
