# New ports collection makefile for:	sim4
# Date created:		27 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	sim4
PORTVERSION=	2000.07.13
CATEGORIES=	biology
MASTER_SITES=	http://globin.cse.psu.edu/ftp/dist/sim4/
DISTNAME=	sim4

MAINTAINER=	johann@egenetics.com

WRKSRC=		${WRKDIR}/sim4.2000-07-13

ALL_TARGET=	sim4

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/sim4 ${PREFIX}/bin

.include <bsd.port.mk>
