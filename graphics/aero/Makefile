# New ports collection makefile for:	aero
# Date created:		Mon Aug 28 13:35:31 CDT 1995
# Whom:			erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	aero
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ee.uwa.edu.au/~braunl/aero/ftp/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libfwf.a:${PORTSDIR}/x11-toolkits/FWF
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_X_PREFIX=	yes
USE_XPM=	yes
MAKEFILE=	Makefile.linux

.include <bsd.port.mk>
