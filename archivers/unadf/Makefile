# New ports collection makefile for:	unadf
# Date created:				1 October 2000
# Whom:					Per Wigren
#
# $FreeBSD$
#

PORTNAME=	unadf
PORTVERSION=	0.7.9b
CATEGORIES=	archivers
MASTER_SITES=	http://perso.club-internet.fr/lclevy/adflib/
DISTNAME=	adflib

MAINTAINER=	wigren@home.se

NO_WRKSUBDIR=	yes
USE_ZIP=	yes

pre-build:
	@${PERL} -pi -e "s@tests lib demo@lib demo@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Demo/unadf ${PREFIX}/bin

.include <bsd.port.mk>
