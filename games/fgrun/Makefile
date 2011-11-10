# New ports collection makefile for:	fgrun
# Date created:				18 Oct 2008
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	fgrun
PORTVERSION=	1.6.0
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	buganini@gmail.com
COMMENT=	A graphical frontend to run FlightGear Flight Simulator

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
BUILD_DEPENDS=	simgear>=2.4.0:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	simgear>=2.4.0:${PORTSDIR}/devel/simgear \
		fgfs:${PORTSDIR}/games/flightgear

.if defined(WITH_OSG_DEVEL)
LIB_DEPENDS+=	osg.59:${PORTSDIR}/graphics/osg-devel
.else
LIB_DEPENDS+=	osg.55:${PORTSDIR}/graphics/osg
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost="${LOCALBASE}"
USE_GMAKE=	yes
USE_GL=		gl

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
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
