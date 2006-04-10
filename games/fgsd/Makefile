# New ports collection makefile for:	fgsd
# Date created:				10 Apr 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fgsd
DISTVERSION=	0.3.1a
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A scenery designer for the FlightGear flight simulator

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
RUN_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib \
		${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear
LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk \
		flu:${PORTSDIR}/x11-toolkits/flu \
		ungif:${PORTSDIR}/graphics/libungif \
		curl:${PORTSDIR}/ftp/curl \
		CGAL:${PORTSDIR}/math/cgal \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		glut:${PORTSDIR}/graphics/libglut

USE_X_PREFIX=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_FILES=	bin/fgsd share/pixmaps/fgsd.xpm
DESKTOP_ENTRIES="FlightGear Scenery Designer" \
		"Edit FlightGear scenery" \
		"fgsd.xpm" \
		"fgsd" \
		"Application;Graphics;" \
		false

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lgif|-lungif|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/curves.xpm ${PREFIX}/share/pixmaps/fgsd.xpm

.include <bsd.port.post.mk>
