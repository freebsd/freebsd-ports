# New ports collection makefile for:	flightgear-atlas
# Date created:				16 Sep 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-atlas
PORTVERSION=	0.3.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/atlas
DISTNAME=	Atlas-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A map viewer for use with the FlightGear flight simulator

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/include/simgear/version.h:${PORTSDIR}/devel/simgear
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		glut.4:${PORTSDIR}/graphics/libglut
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/include/simgear/version.h:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

GNU_CONFIGURE=	yes
USE_GL=		yes

CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-fgbase="${LOCALBASE}/share/FlightGear"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lpthread||' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/AtlasPalette ${LOCALBASE}/share/FlightGear
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
