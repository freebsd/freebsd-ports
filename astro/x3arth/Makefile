# New ports collection makefile for:  	x3arth
# Date created:		15 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x3arth
PORTVERSION=	1.1
CATEGORIES=	astro tcl82
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82 \
		${X11BASE}/bin/xv:${PORTSDIR}/graphics/xv

USE_X_PREFIX=	yes
WRKSRC=	${WRKDIR}/usr/local/bin
NO_BUILD=	yes
STRIP=
USE_BZIP2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x3arth ${PREFIX}/bin

.include <bsd.port.mk>
