# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	FlightGear
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Source/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Source/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	The FlightGear flight simulator

LIB_DEPENDS=	glut:${PORTSDIR}/graphics/libglut \
		openal.0:${PORTSDIR}/audio/openal
BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${X11BASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

USE_X_PREFIX=	yes
USE_GL=		yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--datadir=${X11BASE}/share	# location of fgfs-base
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		est-epsilon.1 fgfs.1 fgjs.1 gl-info.1 js_demo.1 pstest.1

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
