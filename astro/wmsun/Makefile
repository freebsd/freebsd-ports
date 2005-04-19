# New ports collection makefile for:	wmSun
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmsun
PORTVERSION=	1.03
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://dockapps.org/files/16/23/
DISTNAME=	wmSun-1.03

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that displays the rise and set time of the sun

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSun

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	clean all
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		INCDIR="-I${X11BASE}/include" LIBDIR="-L${X11BASE}/lib"

MAN1=		wmSun.1
PLIST_FILES=	bin/wmSun

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmSun ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmSun.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
