# New ports collection makefile for:	wmSun
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmsun
PORTVERSION=	1.03
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/
DISTNAME=	wmSun-1.03

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSun

USE_GMAKE=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	clean all

MAN1=	wmSun.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmSun ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmSun.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
