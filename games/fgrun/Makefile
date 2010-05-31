# New ports collection makefile for:	fgrun
# Date created:				18 Oct 2008
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	fgrun
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	buganini@gmail.com
COMMENT=	A graphical frontend to run FlightGear Flight Simulator

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
BUILD_DEPENDS=	SimGear>=2.0.0:${PORTSDIR}/devel/simgear \
		plib>=1.8.5:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=	SimGear>=2.0.0:${PORTSDIR}/devel/simgear \
		fgfs:${PORTSDIR}/games/flightgear \
		plib>=1.8.5:${PORTSDIR}/x11-toolkits/plib

.if defined(WITH_OSG_DEVEL)
LIB_DEPENDS+=	osg.59:${PORTSDIR}/graphics/osg-devel
.else
LIB_DEPENDS+=	osg.55:${PORTSDIR}/graphics/osg
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS=	--disable-nls
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} 's|SUBDIRS = src po msvc|SUBDIRS = src|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
