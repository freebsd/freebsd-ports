# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	flightgear
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Source/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Source/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Source/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Source/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Source/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	The FlightGear flight simulator

LICENSE=	GPLv2

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		osg.80:${PORTSDIR}/graphics/osg
BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/flightgear/version:${PORTSDIR}/games/flightgear-data

USE_BZIP2=	yes
USE_XORG=	ice sm x11 xext xi xt xmu
USE_GL=		gl glu glut
USE_OPENAL=	al
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--datadir=${LOCALBASE}/share
MAKE_JOBS_UNSAFE=yes

MAN1=	est-epsilon.1 js_demo.1 pstest.1 fgjs.1 gl-info.1 fgfs.1

post-patch:
	@${REINPLACE_CMD} 's|-D_REENTRANT|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/js_server/js_server ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
