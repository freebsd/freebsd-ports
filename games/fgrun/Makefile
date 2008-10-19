# New ports collection makefile for:	fgrun
# Date created:				18 Oct 2008
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	fgrun
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	buganini@gmail.com
COMMENT=	A graphical frontend to run FlightGear Flight Simulator

BUILD_DEPENDS=	fltk-threads>=1.1.0:${PORTSDIR}/x11-toolkits/fltk-threads \
		plib>=1.8.4:${PORTSDIR}/x11-toolkits/plib \
		SimGear>=0.3.10:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	fltk-threads>=1.1.0:${PORTSDIR}/x11-toolkits/fltk-threads \
		plib>=1.8.4:${PORTSDIR}/x11-toolkits/plib \
		SimGear>=0.3.10:${PORTSDIR}/devel/simgear \
		fgfs:${PORTSDIR}/games/flightgear

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_GETTEXT=	yes

.include <bsd.port.mk>
