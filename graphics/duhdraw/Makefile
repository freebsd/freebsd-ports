# New ports collection makefile for:    duhdraw
# Date created:         March 18 2002
# Whom:                 Kyle Martin <mkm@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	duhdraw
PORTVERSION=	2.6.96
CATEGORIES=	graphics
MASTER_SITES=	http://www.wwco.com/~wls/opensource/
DISTNAME=	duhdraw-2.7.1

MAINTAINER=	mkm@ieee.org

WRKSRC=		${WRKDIR}/duhdraw-2.7.1
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ansi ${PREFIX}/bin/ansi
	${INSTALL_SCRIPT} ${WRKSRC}/ansitoc ${PREFIX}/bin/ansitoc
	${INSTALL_SCRIPT} ${WRKSRC}/duhdraw ${PREFIX}/bin/duhdraw

.include <bsd.port.mk>
