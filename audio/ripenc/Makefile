# New ports collection makefile for: ripenc
# Date created:         28 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	ripenc
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	http://home.kc.rr.com/ripenc/

MAINTAINER=	freebsdports@arved.de

WRKSRC=		${WRKDIR}/ripenc

NO_BUILD=	Shell Script

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripenc ${PREFIX}/bin

.include <bsd.port.mk>
