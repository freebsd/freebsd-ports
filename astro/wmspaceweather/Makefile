# New ports collection makefile for:	wmSpaceWeather
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmspaceweather
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://dockapps.org/files/15/22/
DISTNAME=	wmSpaceWeather-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DockApp that shows the weather at geosynchronous orbit

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSpaceWeather

# distfile is actually just a tar with suffix .tar.gz:
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean all

MAN1=	wmSpaceWeather.1

PLIST_FILES=	bin/GetKp bin/wmSpaceWeather

.include <bsd.port.mk>
