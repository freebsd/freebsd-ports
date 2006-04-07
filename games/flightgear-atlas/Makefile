# New ports collection makefile for:	flightgear-atlas
# Date created:				16 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-atlas
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	atlas
DISTNAME=	Atlas-${PORTVERSION}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A map viewer for use with the FlightGear flight simulator

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/include/simgear/version.h:${PORTSDIR}/devel/simgear
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		glut.4:${PORTSDIR}/graphics/libglut
RUN_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/include/simgear/version.h:${PORTSDIR}/devel/simgear \
		${X11BASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GL=		yes

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-fgbase="${X11BASE}/share/FlightGear"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lpthread||' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/AtlasPalette ${X11BASE}/share/FlightGear
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
