# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	FlightGear
PORTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	ftp://ftp.de.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Source/ \
		ftp://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Source/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
		http://ftp3.linux.kiev.ua/pub/fgfs/Source/ \
		ftp://ftp.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
		ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.is.co.za/pub/games/flightgear/ftp/Source/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	The FlightGear flight simulator

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		boost_thread.4:${PORTSDIR}/devel/boost
BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/flightgear-data

.if defined(WITH_OSG_DEVEL)
LIB_DEPENDS+=	osg.59:${PORTSDIR}/graphics/osg-devel
.else
LIB_DEPENDS+=	osg.55:${PORTSDIR}/graphics/osg
.endif

USE_XORG=	ice sm x11 xext xi xt xmu
USE_GL=		gl glu glut
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
# location of flightgear-data
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/share

MAN1=	est-epsilon.1 js_demo.1 pstest.1 fgjs.1 gl-info.1 fgfs.1

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/js_server/js_server ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 800063
BROKEN=	plib joystick support broken with USB2
.endif

.include <bsd.port.post.mk>
