# New ports collection makefile for:	fgsd
# Date created:				10 Apr 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fgsd
DISTVERSION=	0.3.1a
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scenery designer for the FlightGear flight simulator

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${LOCALBASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk \
		flu:${PORTSDIR}/x11-toolkits/flu \
		ungif:${PORTSDIR}/graphics/libungif \
		curl:${PORTSDIR}/ftp/curl \
		CGAL:${PORTSDIR}/math/cgal \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \

BROKEN=		does not build with simgear

USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib"

PLIST_FILES=	bin/fgsd share/pixmaps/fgsd.xpm
DESKTOP_ENTRIES="FlightGear Scenery Designer" \
		"Edit FlightGear scenery" \
		"fgsd.xpm" \
		"fgsd" \
		"Application;Graphics;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|-lgif|-lungif|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/curves.xpm ${PREFIX}/share/pixmaps/fgsd.xpm

.include <bsd.port.mk>
