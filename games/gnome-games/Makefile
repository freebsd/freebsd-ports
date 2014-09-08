# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/games/gnome-games/Makefile,v 1.240 2012/09/01 23:02:09 mezz Exp $

PORTNAME=	gnome-games
PORTVERSION=	2.32.1
PORTREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Game applications package for the GNOME 2 Desktop Environment

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile \
		libclutter-gtk-0.10.so:${PORTSDIR}/graphics/clutter-gtk \
		libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	seed:${PORTSDIR}/devel/seed

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]* gnome-games-3.[0-9]*

USE_PYTHON=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GL=		gl
USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack librsvg2 pygnomedesktop gnomedocutils
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

SCOREFILES=	glines.Large glines.Medium glines.Small gnibbles.1.0 \
	gnibbles.1.1 gnibbles.2.0 gnibbles.2.1 gnibbles.3.0 gnibbles.3.1 \
	gnibbles.4.0 gnibbles.4.1 gnobots2.classic_robots-safe \
	gnobots2.classic_robots-super-safe gnobots2.classic_robots \
	gnobots2.nightmare-safe gnobots2.nightmare-super-safe \
	gnobots2.nightmare gnobots2.robots2-safe gnobots2.robots2-super-safe \
	gnobots2.robots2 gnobots2.robots2_easy-safe \
	gnobots2.robots2_easy-super-safe gnobots2.robots2_easy \
	gnobots2.robots_with_safe_teleport-safe \
	gnobots2.robots_with_safe_teleport-super-safe \
	gnobots2.robots_with_safe_teleport gnomine.Custom \
	gnomine.Large gnomine.Medium gnomine.Small gnotravex.2x2 \
	gnotravex.3x3 gnotravex.4x4 gnotravex.5x5 gnotravex.6x6 gnotski.1 \
	gnotski.10 gnotski.11 gnotski.12 gnotski.13 gnotski.14 gnotski.15 \
	gnotski.16 gnotski.17 gnotski.18 gnotski.19 gnotski.2 gnotski.20 \
	gnotski.21 gnotski.22 gnotski.23 gnotski.24 gnotski.25 gnotski.26 \
	gnotski.27 gnotski.28 gnotski.29 gnotski.3 gnotski.30 gnotski.31 \
	gnotski.32 gnotski.33 gnotski.34 gnotski.35 gnotski.36 gnotski.37 \
	gnotski.4 gnotski.5 gnotski.6 gnotski.7 gnotski.8 gnotski.9 \
	gtali.Colors gtali.Regular mahjongg.bridges mahjongg.cloud \
	mahjongg.confounding mahjongg.difficult mahjongg.dragon mahjongg.easy \
	mahjongg.pyramid mahjongg.tictactoe mahjongg.ziggurat quadrapassel

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libavahi-client.a) || defined(WITH_MDNS)
LIB_DEPENDS+=	libavahi-client.so:${PORTSDIR}/net/avahi-app
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/gnome-sudoku/src/lib/defaults.py.in \
		${WRKSRC}/glchess/src/lib/defaults.py.in
	@${REINPLACE_CMD} -e 's|strip-prefix=games|strip-prefix=Games|' \
		${WRKSRC}/libgames-support/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ggz/gnome-games
.for i in ${SCOREFILES}
	${MV} ${STAGEDIR}${PREFIX}/share/games/${i}.scores \
		${STAGEDIR}${PREFIX}/share/games/${i}.scores.sample
.endfor

.include <bsd.port.post.mk>
