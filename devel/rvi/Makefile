# New ports collection makefile for:	rvi
# Date Created:				2 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	rvi
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.rucus.ru.ac.za/~mtsegaye/rvi/ \
		http://www.databits.net/~petef/distfiles/
DISTNAME=	rvi

MAINTAINER=	petef@databits.net

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rvi ${PREFIX}/bin

.include <bsd.port.mk>
