# New ports collection makefile for:	rvi
# Date Created:				2 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	rvi
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	ftp://rucus.rc.ac.za/users/mtsegaye/
DISTNAME=	rvi

MAINTAINER=	petef@FreeBSD.org

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"CC=${CXX}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rvi ${PREFIX}/bin

.include <bsd.port.mk>
