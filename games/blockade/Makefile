# New ports collection makefile for:	blockade
# Date created:		29 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	blockade
PORTVERSION=	1.00
CATEGORIES=	games
MASTER_SITES=	http://www.geocities.com/TimesSquare/Zone/5267/
DISTFILES=	blockade-1_00-linux.tar.gz

MAINTAINER=	cpiazza@FreeBSD.org

USE_XLIB=	yes

MAN6=	blockade.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blockade ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/blockade.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
