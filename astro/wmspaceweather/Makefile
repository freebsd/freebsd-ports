# New ports collection makefile for:	wmSpaceWeather
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmspaceweather
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/
DISTNAME=	wmSpaceWeather-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DockApp that shows the weather at geosynchronous orbit

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSpaceWeather

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean all

MAN1=	wmSpaceWeather.1

PLIST_FILES=	bin/GetKp bin/wmSpaceWeather

.include <bsd.port.mk>
