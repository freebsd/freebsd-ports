# New ports collection makefile for:	unadf
# Date created:				1 October 2000
# Whom:					Per Wigren
#
# $FreeBSD$
#

PORTNAME=	unadf
PORTVERSION=	0.7.9b
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://perso.club-internet.fr/lclevy/adflib/
DISTNAME=	adflib

MAINTAINER=	wigren@home.se
COMMENT=	Extracts files from .adf-files used by Amiga emulators

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/unadf
USE_ZIP=	yes

pre-build:
	@${REINPLACE_CMD} -e "s@tests lib demo@lib demo@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Demo/unadf ${PREFIX}/bin

.include <bsd.port.mk>
