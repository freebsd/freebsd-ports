# New ports collection makefile for:	wmSpaceWeather
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmspaceweather
PORTVERSION=	1.04
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/
DISTNAME=	wmSpaceWeather-1.04

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSpaceWeather

USE_GMAKE=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	clean all

MAN1=	wmSpaceWeather.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmSpaceWeather ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/GetKp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmSpaceWeather.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
