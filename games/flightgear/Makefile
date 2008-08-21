# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME?=	FlightGear
PORTVERSION?=	${FGVERSION}
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Source/ \
		ftp://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Source/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
		http://flightgear.mxchange.org/pub/fgfs/Source/ \
		http://ftp3.linux.kiev.ua/pub/fgfs/Source/

MAINTAINER?=	ganael.laplanche@martymac.com
COMMENT?=	The FlightGear flight simulator

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal
BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

FGVERSION=	1.0.0

USE_XORG=	ice sm x11 xext xi xt xmu
USE_GL=		gl glu glut
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/share	# location of fgfs-base

MAN1=	est-epsilon.1 js_demo.1 pstest.1 fgjs.1 gl-info.1 fgfs.1

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/js_server/js_server ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
