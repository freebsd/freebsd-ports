# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	fgrun
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	buganini@gmail.com
COMMENT=	A graphical frontend to run FlightGear Flight Simulator

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		osg.80:${PORTSDIR}/graphics/osg
BUILD_DEPENDS=	simgear>=2.4.0:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	simgear>=2.4.0:${PORTSDIR}/devel/simgear \
		fgfs:${PORTSDIR}/games/flightgear

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost="${LOCALBASE}"
USE_GMAKE=	yes
USE_GL=		gl

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} 's|SUBDIRS = src po msvc|SUBDIRS = src|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
