# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/games/gnome-games/Makefile,v 1.240 2012/09/01 23:02:09 mezz Exp $

PORTNAME=	gnome-games
PORTVERSION=	2.32.1
PORTREVISION=	4
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the GNOME 2 Desktop Environment

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		clutter-gtk-0.10:${PORTSDIR}/graphics/clutter-gtk \
		clutter-glx-1.0:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	seed:${PORTSDIR}/devel/seed

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]* gnome-games-3.[0-9]*

USE_BZIP2=	yes
USE_PYTHON=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GL=		gl
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack librsvg2 desktopfileutils \
		pygnomedesktop gnomedocutils
USE_GSTREAMER=	vorbis ogg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sound=gstreamer \
		--disable-tests
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	aisleriot.schemas glchess.schemas glines.schemas \
		gnect.schemas gnibbles.schemas gnobots2.schemas \
		gnome-sudoku.schemas gnomine.schemas gnotravex.schemas \
		gnotski.schemas gtali.schemas iagno.schemas lightsoff.schemas \
		mahjongg.schemas quadrapassel.schemas swell-foop.schemas

#DSC_FILES=	iagno/iagno-client.dsc gnect/data/gnect-client.dsc \
#		gnibbles/gnibbles-client.dsc

MAN6=		glchess.6 glines.6 gnect.6 gnibbles.6 gnobots2.6 \
		gnome-sudoku.6 gnomine.6 gnotravex.6 gnotski.6 \
		gtali.6 iagno.6 mahjongg.6 quadrapassel.6 sol.6

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libavahi-client.a) || defined(WITH_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/gnome-sudoku/src/lib/defaults.py.in \
		${WRKSRC}/glchess/src/lib/defaults.py.in
	@${REINPLACE_CMD} -e 's|strip-prefix=games|strip-prefix=Games|' \
		${WRKSRC}/libgames-support/Makefile.in

post-install:
	${MKDIR} ${PREFIX}/share/ggz/gnome-games
	${CHGRP} games ${LOCALBASE}/share/games
	${CHMOD} g=rwXs ${LOCALBASE}/share/games

#.for dsc in ${DSC_FILES}
#	${INSTALL_DATA} ${WRKSRC}/${dsc} ${PREFIX}/share/ggz/gnome-games/${dsc:T}
#.endfor
	@-update-desktop-database

.include <bsd.port.post.mk>
